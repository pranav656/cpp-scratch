#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <atomic>

class UARTSimulator {
public:
    UARTSimulator (const int baudRate) : baudRate(baudRate)
    {
        // Transmission time 
        // simple simulation:
        // 10 bits are transmitted at a time (8 char bits + 1 start + 1 stop)
        transmissionTime = (10 * 1000000) / baudRate;
    }

    void transmit(char data) {
        std::unique_lock<std::mutex> lock(txMutex);
        txQueue.push(data);
        // Notify the transmitter thread
        // that data is available
        txCondition.notify_one();
    }

    void receive()
    {
        std::unique_lock<std::mutex> lock(rxMutex);
        // the statement below is tricky
        // it releases the mutex and waits for the 
        // rx queue to be non empty. Once the
        // queue is non empty, the lock is acquired again
        rxCondition.wait(lock, [this]{
            return !rxQueue.empty();
        });

        char data = rxQueue.front();
        rxQueue.pop();
        lock.unlock(); // explicitly release the lock

        std::cout<< "Received data : " << data << std::endl;
    }

    void start() {
        // starts the receiver and transmitter asynchronously
        txThread = std::thread(&UARTSimulator::transmitter, this);
        rxThread = std::thread(&UARTSimulator::receiver, this);
    }

    void join() {
        // synchronization, ensures
        // both threads are complete
        // before the program terminates
        txThread.join();
        rxThread.join();
    }

    void stop() {
        {
            //std::lock_guard<std::mutex> lock(txMutex);
            //std::lock_guard<std::mutex> lock2(rxMutex);
            //terminateThreads = true;
            // use defer lock to defer locking mutexes 
            std::unique_lock<std::mutex> lock1(txMutex, std::defer_lock);
            std::unique_lock<std::mutex> lock2(rxMutex, std::defer_lock);
            // lock simultaneously to prevent deadlocks
            std::lock(lock1, lock2);
           terminateThreads = true;
        }
        txCondition.notify_one();
        rxCondition.notify_one();
    }

private:
    int baudRate;
    int transmissionTime; // in microseconds

    // queue data structure used
    // to simulate receiving/tranmsitting
    std::queue<char> txQueue;
    std::queue<char> rxQueue;

    // mutex to restrict 
    // access to queueus
    std::mutex txMutex;
    std::mutex rxMutex;

    // condition variables are used for
    // synchronization between threads to manage
    // transmission and reception of data
    // Condition variables are used to block
    // one ore more threads until a particular condition
    // is met. 
    std::condition_variable txCondition;
    std::condition_variable rxCondition;

    // Threads to transmit and
    // receive data asynchornously
    std::thread txThread;
    std::thread rxThread;

    // Atomic flag to signal thread termination
    // used for thread safety
    std::atomic<bool> terminateThreads;

    void transmitter() {
        while(true) {
            std::unique_lock<std::mutex> lock(txMutex);
            txCondition.wait(lock, [this] {
                return (!txQueue.empty() || terminateThreads);
            });

            if(terminateThreads) {
                return;
            }

            char data = txQueue.front();
            txQueue.pop();
            lock.unlock();

            // Simulate the transmission time for the whole frame (start bit
            // data bits and stop bit)
            std::this_thread::sleep_for(std::chrono::microseconds(transmissionTime));
            {
                std::lock_guard<std::mutex> lock(rxMutex);
                rxQueue.push(data);
            }
            rxCondition.notify_one();
        }
    }

    void receiver() {

        while(true) {
            {
                std::unique_lock<std::mutex> lock(rxMutex);
                rxCondition.wait(lock, [this] {
                    return (!rxQueue.empty() || terminateThreads);
                });

                if(terminateThreads) {
                    return;
                }
            }
            receive();
        }
    }
};

int main()
{

    UARTSimulator uart(9600);

    uart.start();
    uart.transmit('H');
    uart.transmit('e');
    uart.transmit('l');
    uart.transmit('l');
    uart.transmit('o');

    // simulate a delay
    std::this_thread::sleep_for(std::chrono::seconds(1));

    uart.stop();

    uart.join();
    
    return 0;
}

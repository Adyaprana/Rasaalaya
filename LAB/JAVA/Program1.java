// Program 1: Producer-Consumer Problem using Threads

class Buffer {
    private int[] buffer;
    private int count = 0;
    private int size;

    public Buffer(int size) {
        this.size = size;
        buffer = new int[size];
    }

    public synchronized void produce(int item) throws InterruptedException {
        while (count == size) {
            wait();
        }
        buffer[count++] = item;
        System.out.println("Produced: " + item);
        notifyAll();
    }

    public synchronized int consume() throws InterruptedException {
        while (count == 0) {
            wait();
        }
        int item = buffer[--count];
        System.out.println("Consumed: " + item);
        notifyAll();
        return item;
    }
}

class Producer implements Runnable {
    private Buffer buffer;

    public Producer(Buffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        int item = 0;
        try {
            while (item < 10) { // Example of producing 10 items
                buffer.produce(item);
                item++;
                Thread.sleep(1000); // Sleep for demonstration
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class Consumer implements Runnable {
    private Buffer buffer;

    public Consumer(Buffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        try {
            while (true) { // Consumes indefinitely
                buffer.consume();
                Thread.sleep(1000); // Sleep for demonstration
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class Program1 {
    public static void main(String[] args) {
        Buffer buffer = new Buffer(5); // Buffer size of 5
        Thread producerThread = new Thread(new Producer(buffer));
        Thread consumerThread = new Thread(new Consumer(buffer));

        producerThread.start();
        consumerThread.start();
    }
}
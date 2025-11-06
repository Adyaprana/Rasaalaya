// Program 5 Producer-Consumer with Executor service

import java.util.concurrent.*;

class Producer implements Runnable {
    private final BlockingQueue<Integer> queue;
    private final int produceCount;

    public Producer(BlockingQueue<Integer> queue, int produceCount) {
        this.queue = queue;
        this.produceCount = produceCount;
    }

    @Override
    public void run() {
        try {
            for (int i = 1; i <= produceCount; i++) {
                System.out.println("Producer produced: " + i);
                queue.put(i);
                Thread.sleep(200);
            }
            queue.put(-1); // stop signal for consumer
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class Consumer implements Runnable {
    private final BlockingQueue<Integer> queue;

    public Consumer(BlockingQueue<Integer> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        try {
            while (true) {
                Integer item = queue.take();
                if (item == -1) {
                    System.out.println("Consumer received stop signal. Exiting.");
                    break;
                }
                System.out.println("Consumer consumed: " + item);
                Thread.sleep(300);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class Program5 {
    public static void main(String[] args) {
        BlockingQueue<Integer> queue = new ArrayBlockingQueue<>(5);
        ExecutorService executor = Executors.newFixedThreadPool(2);

        executor.submit(new Producer(queue, 10));
        executor.submit(new Consumer(queue));
        executor.shutdown();
    }
}
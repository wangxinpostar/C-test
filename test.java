public class MultiThreadExample {
    private int count = 0; // 共享变量
    private final Object lock = new Object(); // 锁对象，final修饰确保线程安全

    // 增加count的方法，使用synchronized关键字保护共享变量
    public void increment() {
        synchronized(lock) { // 获取锁
            count++; // 修改共享变量
        } // 释放锁
    }

    // 减少count的方法，使用synchronized关键字保护共享变量
    public void decrement() {
        synchronized(lock) { // 获取锁
            count--; // 修改共享变量
        } // 释放锁
    }

    // 获取当前的count值
    public int getCount() {
        return count;
    }

    public static void main(String[] args) throws InterruptedException {
        MultiThreadExample example = new MultiThreadExample(); // 创建实例

        // 创建两个线程，一个线程增加count，另一个线程减少count
        Thread thread1 = new Thread(new Runnable() {
            public void run() {
                for (int i = 0; i < 1000000; i++) {
                    example.increment(); // 调用增加count的方法
                }
            }
        });

        Thread thread2 = new Thread(new Runnable() {
            public void run() {
                for (int i = 0; i < 1000000; i++) {
                    example.decrement(); // 调用减少count的方法
                }
            }
        });

        // 启动两个线程
        thread1.start();
        thread2.start();

        // 等待两个线程完成
        thread1.join();
        thread2.join();

        // 输出最终的count值
        System.out.println("Count: " + example.getCount());
    }
}

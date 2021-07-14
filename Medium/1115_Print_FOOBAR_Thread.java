/*
    Notes:
        - Need the two threads to be called in certain order.
        - Maybe make one thread wait for the other.




*/


class FooBar {
        private int n;

        volatile boolean callFoo;
        volatile boolean callBar;

        public FooBar(int n) {
            this.n = n;
            callFoo = true;
            callBar = false;
        }

        public synchronized void foo(Runnable printFoo) throws InterruptedException {

            for (int i = 0; i < n; i++) {
                while (callBar) {
                    wait();
                    // java.lang.Object.wait() causes current thread to wait until another thread invokes the notify() method or the notifyAll() method for this object.
                }
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                callFoo = false;
                callBar = true;
                notifyAll();
            }
        }

        public synchronized void bar(Runnable printBar) throws InterruptedException {

            for (int i = 0; i < n; i++) {
                while (callFoo) {
                    wait();
                }
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                callBar = false;
                callFoo = true;
                notifyAll();
            }
        }
    }
import java.util.*;


class Global{
    public static volatile List<quicksortThread> allThreads;
    public static volatile double timePassed;
    public static volatile int thcount;

    public static int max(int a, int b){
        if(a>b) return a;
        return b;
    }

    public static void shuffleArray(int[] array){
        int index;
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--)
        {
            index = random.nextInt(i + 1);
            if (index != i)
            {
                array[index] ^= array[i];
                array[i] ^= array[index];
                array[index] ^= array[i];
            }
        }
    }

    public static void printArray(int[] a, int N, String text){
        System.out.println("\n"+text+":");
        for(int i=0; i<N; i++){
            System.out.print(a[i]+" ");
        }
        System.out.println("\n");
    }

    public static void isArraySorted(int[] a, int N){
        for(int i=0; i<N-1; i++){
            if(a[i]>a[i+1]){
                System.out.print("\n  The array is not sorted\n");
                return;
            }
        }
        System.out.print("\n  The array is sorted\n");
    }
}

class quicksortThread implements Runnable{
    int[] a;
    int lb, ub;
    int minElementsToCreateNewThread;
    boolean PRINTING;


    private Thread th;
    public Thread.State getState() {
        return th.getState();
    }
    public void start(){
        th = new Thread(this);
        th.start();
    }

    quicksortThread(int[] a, int lb, int ub, int minElementsToCreateNewThread, boolean PRINTING){
        this.a = a;
        this.lb = lb;
        this.ub = ub;
        this.minElementsToCreateNewThread = minElementsToCreateNewThread;
        this.PRINTING = PRINTING;
    }


    public void run(){
        quicksort(a, lb ,ub);
    }

    void quicksort(int[] a, int lb, int ub){
        int i,j,temp;
        int pivpos, pivot;
        if(lb<ub){
            i=lb;
            j=ub;
//            pivpos = ((int)(Integer.MAX_VALUE*Math.random()))%(ub-lb+1) + lb;
//            temp = a[lb];
//            a[lb] = a[pivpos];
//            a[pivpos] = temp;

            pivpos = lb;
            pivot = a[pivpos];

            if(PRINTING)
                System.out.println("I am handling indices: "+lb+"-"+ub+"; I chose pivot as a["+pivpos+"]="+pivot);
            while(i<j){
                i++;
                while(i<=ub && a[i]<pivot)
                    i++;
                while(j>=lb && a[j]>pivot)
                    j--;
                if(i<j){
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            temp = a[j];
            a[j] = a[pivpos];
            a[pivpos] = temp;

            // if there are too many elements, partition the array and assign it to threads.
            // if not, then just do it recursively
            int leftPartitionLB = lb, leftPartitionUB = j-1;
            if(leftPartitionUB - leftPartitionLB > minElementsToCreateNewThread){
                if(PRINTING)
                    System.out.println("    I am thread("+lb+"-"+ub+"), "
                            + "and I'm making a new thread for indices "
                            + "("+leftPartitionLB+"-"+leftPartitionUB+")");
                quicksortThread qsth = new quicksortThread(a, leftPartitionLB, leftPartitionUB, this.minElementsToCreateNewThread, this.PRINTING);
                Global.allThreads.add(qsth);
                qsth.start();
            }
            else quicksort(a, leftPartitionLB, leftPartitionUB);

            int rightPartitionLB = j+1, rightPartitionUB = ub;
            if(rightPartitionUB - rightPartitionLB > minElementsToCreateNewThread){
                if(PRINTING)
                    System.out.println("    I am thread("+lb+"-"+ub+"), "
                            + "and I'm making a new thread for indices "
                            + "("+rightPartitionLB+"-"+rightPartitionUB+")");
                quicksortThread qsth = new quicksortThread(a, rightPartitionLB, rightPartitionUB, this.minElementsToCreateNewThread, this.PRINTING);
                Global.allThreads.add(qsth);
                qsth.start();
            }
            else quicksort(a, rightPartitionLB, rightPartitionUB);
        }
    }
}

public class quicksortRecursiveThreads{

    static void runQuickSort(int[] a, int N, int approxNumThreads) throws InterruptedException{
        Global.shuffleArray(a);
        double timePassed = System.currentTimeMillis();
        Global.allThreads = new ArrayList<quicksortThread>();
        quicksortThread main_qsth = new quicksortThread(a, 0, N-1, (int)(N/(double)(approxNumThreads/1.95)), false); // 1.95 was calculated approximately; it's got to do with the log of the quicksort, and is the average branching factor??
        Global.allThreads.add(main_qsth);
        main_qsth.start();
        boolean done = false;
        int thcount = 1;
        while(!done){
            done = true;
            thcount = Global.max(thcount, Global.allThreads.size());
            for(int i=0; i<Global.allThreads.size(); i++){
                if(Global.allThreads.get(i)!=null && Global.allThreads.get(i).getState() != Thread.State.TERMINATED){
                    done = false;
                    break;
                }
            }
            Thread.sleep(1);
        }
        timePassed = System.currentTimeMillis() - timePassed;
        timePassed = ((double)timePassed)/1000;
        // Thread.sleep(1000);
//        Global.printArray(a, N, "Sorted array");
        // Global.isArraySorted(a,N);
        Global.timePassed = timePassed;
        Global.thcount = thcount;
    }

    public static void main(String args[]) throws InterruptedException{
        int N = 10000000;
        int a[] = new int[N];
        Random rand = new Random();
        for(int i=0; i<N; i++){
            int lowerBound = 0, upperBound = N-1;
            a[i] = rand.nextInt(upperBound - lowerBound + 1) + lowerBound;
            // a[i] = i;
        }
        System.out.print("  Created array of "+N+" elements.");
//        Global.printArray(a, N, "Unsorted array");
        int[] approxNumThreads = {1,3,5,10,50,100,500,1000,3000,4000,5000,6000,7500,9000, 10000};
        for(int i=0; i<approxNumThreads.length; i++){
            int numIter = 10;
            double avgTimePassed = 0 ;
            double avgThCount = 0;
            for(int j=0; j<numIter; j++){
                runQuickSort(a, N, approxNumThreads[i]);
                avgTimePassed += Global.timePassed;
                avgThCount += Global.thcount;
            }
            avgTimePassed /= (double) numIter;
            avgThCount /= (double) numIter;
            System.out.println("\n  Avg Time taken: "+avgTimePassed + " seconds." );
            System.out.println("  Avg Number of threads created: "+avgThCount + " (approx="+approxNumThreads[i]+")");
            System.out.println("");
        }

    }
}

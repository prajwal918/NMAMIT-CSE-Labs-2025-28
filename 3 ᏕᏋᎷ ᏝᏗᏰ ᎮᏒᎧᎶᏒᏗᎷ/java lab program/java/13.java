class callme {
    synchronized static void call(String msg) {
        System.out.print("[" + msg); // Corrected from printhal $...
        try {
            Thread.sleep(1000); // Corrected from Sleep (1000),
        } catch (InterruptedException e) {
            System.out.println("Interrupted");
        }
        System.out.println("]"); // Corrected from printin ""J"")
    }
}

class caller extends Thread {
    String msg;

    public caller(String s) { // Corrected from (String )
        msg = s; // Corrected from $msg=5,$
    }

    public void run() {
        callme.call(msg); // Corrected from Callme Pall
    }
}

class threaddemo { // Corrected from thread demor
    public static void main(String[] args) {
        Caller C1 = new Caller("Learn"); // Corrected from $Cl=new~catler(u~Leasen^{4});$
        Caller C2 = new Caller("Java"); // Corrected from $C2=neuo~cattex(^{v}Java^{u})$;
        Caller C3 = new Caller("Programming"); // Corrected from (3= new caller...
        C1.start(); // Corrected from CI Start()
        C2.start(); // Corrected from C2.Start()
        C3.start(); // Corrected from C3 Start()
    }
}
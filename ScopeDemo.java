public class ScopeDemo {
    private static int globalVar = 10;

    public void displayFormalParameter(int formalParam) {
        System.out.println("Formal parameter value: " + formalParam);
    }

    public void demonstrateLocalScope() {
        int localVar = 20;
        System.out.println("Local variable value: " + localVar);
    }

    private void demonstrateAccessModifiers() {
        System.out.println("Global variable (private): " + globalVar);
    }

    public static void main(String[] args) {
        ScopeDemo demo = new ScopeDemo();

        System.out.println("Global variable (public): " + globalVar);

        demo.displayFormalParameter(30);
        demo.demonstrateLocalScope();
        demo.demonstrateAccessModifiers();
    }
}

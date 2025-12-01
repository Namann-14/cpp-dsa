    class Main {
        private static int solve(int n) {
            if (n <= 0) return 0;
            return (n % 10) + solve(n / 10);
        }
        public static  int power(int base,int exp){
            if(exp ==0) return 1;
            return(base*power(base,exp-1));
        }
        public static void main(String[] args) {
            int n = 1234;
            System.out.println(solve(n));

            int base = 2;
            int exp = 2;
            System.out.println(power(base, exp));
        }
    }
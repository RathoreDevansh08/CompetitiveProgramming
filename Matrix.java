class Matrix
{
    public static int[][] createArray()
    {
        int[][] s = new int[2][2];
        s[0][0] = 1;
        s[0][1] = 2;
        s[1][0] = 3;
        s[1][1] = 4;
        return s;
    }

    public static void main(String args[])
    {
        //MatrixRot m = new MatrixRot();
        int[][] a = createArray();
        System.out.println(a[0][1]);
        System.out.println();
    }
}

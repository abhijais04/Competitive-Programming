import java.util.*;
import java.lang.*;
import java.math.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int i;
		Scanner k=new Scanner(System.in);
		int t=1024;
		for(i=0;i<t;i++)
		{
			BigInteger ta=k.nextBigInteger();
			//BigInteger tb=k.nextBigInteger();			
			//BigInteger tc=k.nextBigInteger();
			BigInteger d=new BigInteger("2");
			BigInteger a=new BigInteger("1");
			if(ta.equals(a))
			{
				System.out.println("1");
			}
			else
			{
				ta=ta.multiply(d);
				ta=ta.subtract(d);
				System.out.println(ta);
			}
		}
	}
}
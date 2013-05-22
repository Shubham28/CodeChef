import java.math.*;
import java.io.DataInputStream;
import java.io.InputStream;

public class Main
{
	static BigInteger xcord,ycord,absx,absy;

	static BigInteger calNumber()
	{
		BigInteger zero=BigInteger.valueOf(0);
		BigInteger one=BigInteger.valueOf(1);

		if(xcord.equals(zero)){
			if(ycord.equals(zero))
				return zero;
			else if(ycord.equals(one))
				return BigInteger.valueOf(3);
		} else if(xcord.equals(one)){
			if(ycord.equals(zero))
				return one;
			else if(ycord.equals(one))
				return BigInteger.valueOf(2);
		}

		// 1st Quadrant
		if(xcord.compareTo(zero)>=0 && ycord.compareTo(zero)>=0){
			BigInteger len=(xcord.compareTo(ycord)>=0)?xcord:ycord;
			len=len.subtract(one);
			BigInteger strt=( BigInteger.valueOf(4) ).multiply( len.multiply(len) );
			BigInteger num=strt.add( (BigInteger.valueOf(5)).multiply(len) );
			num=num.add( one.add(ycord) );
			num=num.add( len.add( one.subtract(xcord) ) );
			return num;
		}

		// 2nd Quadrant
		if(xcord.compareTo(zero)<=0 && ycord.compareTo(zero)>=0){
			absx=xcord.multiply(BigInteger.valueOf(-1));
			BigInteger len=(absx.compareTo(ycord)>=0)?absx:ycord;
			BigInteger strt=( BigInteger.valueOf(4) ).multiply( len.multiply(len) );
			strt=strt.subtract(len);
			BigInteger num=strt.subtract(xcord);
			num=num.add( len.subtract(ycord) );
			return num;
		}

		// 3rd Quadrant
		if(xcord.compareTo(zero)<=0 && ycord.compareTo(zero)<=0){
			absx=xcord.multiply(BigInteger.valueOf(-1));
			absy=ycord.multiply(BigInteger.valueOf(-1));
			BigInteger len=(absx.compareTo(absy)>=0)?absx:absy;
			BigInteger strt=( BigInteger.valueOf(4) ).multiply( len.multiply(len) );
			strt=strt.add(len);
			BigInteger num=strt.subtract(ycord);
			num=num.add( len.add(xcord) );
			return num;
		}

		// 4th Quadrant
		if(xcord.compareTo(zero)>=0 && ycord.compareTo(zero)<=0){
			absy=ycord.multiply(BigInteger.valueOf(-1));
			BigInteger len=((xcord.subtract(one)).compareTo(absy)>=0)?(xcord.subtract(one)):absy;
			BigInteger strt=( BigInteger.valueOf(4) ).multiply( len.multiply(len) );
			strt=strt.add( len.multiply(BigInteger.valueOf(3)) );
			BigInteger num=strt.add(xcord);
			num=num.add( len.add(ycord) );
			return num;
		}

		return zero;
	}

	public static void main(String args[])
	{
		try
		{
			ParserLose inpt=new ParserLose(System.in);
			StringBuffer outpt=new StringBuffer(600000);

			int T=inpt.nextInt();

			int loop;
			for(loop=1;loop<=T;loop++)
			{
				int inpx=inpt.nextInt();
				int inpy=inpt.nextInt();

				int ans=999;
				BigInteger val;
				boolean itself=false;

				xcord=BigInteger.valueOf(inpx);
				ycord=BigInteger.valueOf(inpy);
				val=calNumber();
				if(val.isProbablePrime(1)){
					ans=0;
					itself=true;
				}

				outer: for(int ran=1;ran<=200 && !itself;ran++){

					for(int fir=0;fir<=ran;fir++){
						xcord=BigInteger.valueOf(inpx+fir);
						ycord=BigInteger.valueOf(inpy+ran-fir);
						val=calNumber();
						if(val.isProbablePrime(1)){
							ans=ran;
							break outer;
						}
					}
					for(int fir=-ran;fir<=0;fir++){
						xcord=BigInteger.valueOf(inpx+fir);
						ycord=BigInteger.valueOf(inpy+ran+fir);
						val=calNumber();
						if(val.isProbablePrime(1)){
							ans=ran;
							break outer;
						}
					}

					for(int fir=-ran;fir<=0;fir++){
						xcord=BigInteger.valueOf(inpx+fir);
						ycord=BigInteger.valueOf(inpy-ran-fir);
						val=calNumber();
						if(val.isProbablePrime(1)){
							ans=ran;
							break outer;
						}
					}

					for(int fir=0;fir<=ran;fir++){
						xcord=BigInteger.valueOf(inpx+fir);
						ycord=BigInteger.valueOf(inpy-ran+fir);
						val=calNumber();
						if(val.isProbablePrime(1)){
							ans=ran;
							break outer;
						}
					}
				}

				outpt.append(ans);
				outpt.append("\n");
			}

			System.out.print(outpt.toString());
		}
	catch(Exception e){}
	}
}

class ParserLose
{
	final private int BUFFER_SIZE = 1 << 16;
	private DataInputStream din;
	private byte[] buffer;
	private int bufferPointer,bytesRead;

	public ParserLose(InputStream in)
	{
		din=new DataInputStream (in);
		buffer=new byte[BUFFER_SIZE];
		bufferPointer=bytesRead=0;
	}

	public String nextString() throws Exception
	{
		StringBuffer sb=new StringBuffer("");
		byte c = read();

		while(c<=' ')
			c=read();

		do
		{
			sb.append((char)c);
			c=read();
		} while(c>' ');

		return sb.toString();
	}

	public char nextChar() throws Exception
	{
		byte c=read();
		while(c<=' ')
			c=read();

		return (char)c;
	}

	public int nextInt() throws Exception
	{
		int ret=0;
		byte c =read();
		while(c<=' ')
			c=read();

		boolean neg=(c=='-');
		if(neg)
			c=read();
		do{
			ret=(ret<<3)+(ret<<1)+(c-'0');
			c=read();
		} while(c>' ');

		if(neg)
			return -ret;
		return ret;
	}

	private byte read() throws Exception
	{
		if(bufferPointer==bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}

	private void fillBuffer() throws Exception
	{
		bytesRead=din.read(buffer,bufferPointer=0,BUFFER_SIZE);
		if(bytesRead==-1)
			buffer[0]=-1;
	}
}

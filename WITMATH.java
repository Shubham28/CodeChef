import java.math.*;
import java.io.DataInputStream;
import java.io.InputStream;

public class Main
{
	private static StringBuffer outpt;

	private static void addNum(long N)
	{
		outpt.append(N);
		outpt.append("\n");
	}
	private static boolean checkNum(long N)
	{
		BigInteger posb=BigInteger.valueOf(N);
		if(posb.isProbablePrime(5)){
			addNum(N);
			return true;
		}
		return false;
	}

	public static void main(String args[])
	{
		try
		{
			ParserLose inpt=new ParserLose(System.in);
			outpt=new StringBuffer(60000);

			int T=(int)inpt.nextLong();

			long N;
			for(int cs=0;cs<T;cs++){
				N=inpt.nextLong();

				if(N<=4){
					addNum(Math.min(3l,N));
					continue;
				} else if(N<=6){
					addNum(5);
					continue;
				}

				int dif=(int)(N%6l);
				if(dif==5){
					if(checkNum(N))
						continue;
				} else if(dif==0){
					if(checkNum(N-1))
						continue;
					N-=6;
				}

				for(long chk=N-dif;chk>=6;chk-=6){
					if(checkNum(chk+1))
						break;
					if(checkNum(chk-1))
						break;
				}
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

	public long nextLong() throws Exception
	{
		long ret=0;
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

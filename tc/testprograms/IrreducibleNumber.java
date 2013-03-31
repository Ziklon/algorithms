public class IrreducibleNumber {

	public int getIrreducible(int[] A) {
		int dev=0;
		boolean ok=true;
		for(dev=1;ok;dev++){
			ok=false;
			for(int i=1;i<(1<<A.length);i++){
				int tmp=0;
				for(int j=0;j<A.length;j++)
					if((i&(1<<j))>0)
						tmp+=A[j];
				if(tmp==dev)
					ok=true;
			}			
		}
		return dev-1;
	}

}

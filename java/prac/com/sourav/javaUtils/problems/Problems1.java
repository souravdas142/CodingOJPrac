package com.sourav.javaUtils.problems;

import java.lang.*;
import java.util.Scanner;

public class Problems1 {
	
	int x, y;

	public Problems1(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int[] performPrimeBase() {

		final int absc = Math.abs(x/2) + 1;

		int[] arr = new int[absc];
		int k = 0;


		boolean isPrime = true;

		for(int i = 3;i<x;i+=2) {
			isPrime = true;
			for(int j = 3; j*j<=i;j+=2) {
				if(i%j==0)
					isPrime = false;
			}

			if(isPrime) {
				arr[k++] = i;
				System.out.println(" "+i+" ");
			}

		}
		return arr;
	}

	void performPrime() {
		
		int[] primeBase = performPrimeBase();
		int[] primeNumber = new int[y];

		for(int i =0;i<primeBase.size() && primeBase[i]!=null;i++) {

			int p = (x/primeBase[i]) * primeBase[i];

			for(int j = p;j*j<y;j+=p) {

				primeNumber[p] = 0;
			}
		}


		for(int k = x;k<=y;k++) {
			if(primeNumber[k] == 1) {
				System.out.println(" " + k  + " ");
			}
		}



	}


}

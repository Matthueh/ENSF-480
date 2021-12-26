/*	
 * 		File Name: BubbleSorter.java
 * 		Assignment Lab 5 exercise A
 * 		Completed By: Matthew Ho and Alexander Sembrat
 * 		Submission Date: 11/4/2021
 */
import java.util.ArrayList;

public class BubbleSorter<E extends Number & Comparable<E> > implements Sorter<E>{



	//This method should be able to take on any value.
	//This method should work for bubble sort.
	@Override
	public void sort(ArrayList<Item<E>> storageM) {
		//This will implement the bubble sorting technique
		for(int i = 0; i < storageM.size() - 1; i++) {
			for(int j = 0; j < storageM.size() - i - 1; j++) {
				if(storageM.get(j).compareTo(storageM.get(j+1)) > 0) {
					Item<E> temp =  storageM.get(j);
					storageM.set(j, storageM.get(j+1));
					storageM.set(j+1, temp);
				}
			}
		}
	}


	
	
	
}

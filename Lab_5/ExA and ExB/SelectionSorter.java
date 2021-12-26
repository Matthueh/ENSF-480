/*	
 * 		File Name: SelectionSorter.java
 * 		Assignment Lab 5 exercise B
 * 		Completed By: Matthew Ho and Alexander Sembrat
 * 		Submission Date: 11/4/2021
 */
import java.util.ArrayList;

public class SelectionSorter<E extends Number & Comparable<E>> implements Sorter<E>{

	@Override
	public void sort(ArrayList<Item<E>> storageM) {
		for(int i = 0; i < storageM.size() - 1; i++ ) {
			int minimum = i;
			for(int j = i + 1; j < storageM.size(); j++) {
				if(storageM.get(j).compareTo(storageM.get(minimum)) < 0){
					minimum = j;
				}
			}
			
			Item<E> temp = storageM.get(minimum);
			storageM.set(minimum, storageM.get(i));
			storageM.set(i, temp);
		}
	}


}

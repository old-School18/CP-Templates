// Time Complexity: O(n^2) Worst | O(n^2) Average | O(n) Best
// Memory Complexity: O(1)
// Stable: Yes
// Mechanism to sort sequences by moving the next largest element to the last index of the shrinking BUBBLE

void bubble_sort(ll a[], ll n)
{
    bool swapped=true;
    
    for(ll i=n-1;i>=0&&swapped;i--) {
    	swapped=false;
    	for(ll j=0;j<i;j++) {
    		if(a[j]>a[j+1]) {
    			swapped=true;
    			swap(a[j],a[j+1]);
    		}
    	}
    }
    
    return;
}

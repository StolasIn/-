class maxheap{
public:
    heap(){
        heap_array=vector<int>();
        heap_size=0;
        heap_array.emplace_back(0);
    }
    void push(int x){
        heap_array.emplace_back(x);
        heap_size++;
        push_heapify();
    }
    void pop(){
        if(heap_size>0){
            swap(heap_array[1],heap_array[heap_size]);
            heap_array.pop_back();
            heap_size--;
            pop_heapify();
        }
        else{
            printf("heap is empty.");
        }
    }
    int top(){
        if(empty()==false){
            return heap_array[1];
        }
        else{
            printf("heap is empty , return 0. ");
            return 0;
        }
    }
    int size(){
        return heap_size;
    }
    bool empty(){
        if(heap_size==0) return true;
        return false;
    }
    void print_array(){
        for(int i=1;i<=size();i++){
            printf("%3d",heap_array[i]);
        }
        printf("\n");
    }

private:
    vector<int> heap_array;
    int heap_size;

    void push_heapify(){
        int m=heap_size;
        while(heap_array[m]>heap_array[m/2] && m/2!=0){
            swap(heap_array[m],heap_array[m/2]);
            m/=2;
        }
    }
    void pop_heapify(){
        if(heap_size==1){
            return;
        }
        else if(heap_size==2){
            if(heap_array[1]<heap_array[2]) swap(heap_array[1],heap_array[2]);
        }
        else if(heap_size>=3){
            int root=1;
            int left=2;
            int right=3;
            int max1;
            while((left<heap_size && right<=heap_size) && (heap_array[root]<heap_array[left] || heap_array[root]<heap_array[right])){
                max1=left;
                if(heap_array[max1]<heap_array[right]) max1=right;
                swap(heap_array[root],heap_array[max1]);
                if(max1==left){
                    root=left;
                    left=root*2;
                    right=root*2+1;
                }
                else{
                    root=right;
                    left=root*2;
                    right=root*2+1;
                }
            }
        }
    }
};
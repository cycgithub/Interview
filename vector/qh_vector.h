#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_

namespace qh
{
    template<class T>
    class vector {
		enum{CAPACITY=5};
    public:
        //ctor
        vector()
            : data_(NULL), size_(0),capacity_(CAPACITY)
        {
			data_=new T[capacity_];
        }

        explicit vector( size_t n, const T& value = T())
        {
            data_ = new T[n+CAPACITY];
            for (size_t i = 0; i < n+CAPACITY; i++)
            {
                data_[0] = value;
            }
        }
        //cyc edit 
        vector<T>& operator=(const vector<T>& rhs)
        {
           /* data_ = rhs.data_;
            size_ = rhs.size_;*/
			if(this!=&rhs)
			{
				delete[] data_;
				size_=rhs.size();
				
				capacity_=rhs.capacity();
				
				data_=new T[rhs.capacity()];
				for(int k=0;k<rhs.size();++k)
					data_[k]=rhs.data_[k];
			}
			return *this;
        }

        //dtor
        ~vector()
        {
            if (data_!=NULL)
            {
                delete[] data_;
            }
        }

        //get
        size_t size() const
        {
            return size_;
        }

        // set & get
		//cyc edit
        T& operator[](size_t index)
		{
			size_t ss=size_;
			if(ss>0)ss--;
			if(index<=ss)
			{
			   return data_[index];
			}
		}

        // set
		//cyc edit
        void push_back(const T& element)
		{
			if(size_==capacity_)
			{
				ReAlloc(2*capacity_+1);
			}
			data_[size_++]=element;
		}
		//cyc edit
        void pop_back()
		{
			if(size_>0)
			size_--;
		}
		//cyc edit  modify size_
        void resize(int newsize)
		{
			if(newsize<capacity_)size_=newsize;
			else
			{
				ReAlloc(newsize*2);
				size_=newsize;
			}
		}
		//cyc edit   modify capacity_
        void reserve(int newsize)
		{
			if(newsize>capacity_)
				ReAlloc(newsize*2);
			//size_=newsize;
		}
		//cyc edit
		void clear(){size_=0;}
		 size_t capacity()const{return capacity_;}
		//cyc edit
		bool empty()const{return size()==0;}
		//cyc edit
		void ReAlloc(int Capacity)
		{
			if(Capacity<size_)return;
			T *temp=data_;
			data_=new T[Capacity];
			for(int i=0;i<size_;++i)
				data_[i]=temp[i];
			capacity_=Capacity;
			delete[] temp;
		}

    private:
        T*      data_;
        size_t  size_;
		//cyc edit
		size_t  capacity_;
    };
}

#endif
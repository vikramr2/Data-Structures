template<typename T>
class List {
	private:
		struct Node {
			T elem;
			Node* next;
			Node* prev;
		};
	public:
		class Iterator {
			public:
				T& operator*() { return v->elem; }
				bool operator==(const Iterator& p) const { return v == p.v; }
				bool operator!=(const Iterator& p) const { return v != p.v; }
				Iterator& operator++() { v = v->next; return *this; }
				Iterator& operator--() { v = v->prev; return *this; }
				friend class List;
			private:
				//current node
				Node* v;
				
				//since List is a friend, it should be able to access this
				Iterator(Node* u) { v = u; }
		};
	public:
		//ctors
		List() : n(0), header(new Node), trailer(new Node) {
			header->next = trailer;
			trailer->prev = header;
		}
		List(const List& l) {
			n = l.n;
			header = l.header;
			trailer = l.trailer;
		}
		List& operator=(const List& l) {
			if (this != &l) {
				n = l.n;
				header = l.header;
				trailer = l.trailer;
			}
			return *this;
		}
		
		//dtor
		~List() {
			while (!empty()) eraseFront();
			delete header;
			delete trailer;
		}
		
		int size() const { return n; }
		bool empty() const { return (n==0); }
		
		//iterators
		Iterator begin() const { return Iterator(header->next); }
		Iterator end() const { return Iterator(trailer); }
		
		//insertions
		void insert(const Iterator& p, const T& e) {
			Node* w = p.v;       Node* u = w->prev; //initialize targets
			Node* v = new Node;  v->elem = e;       //initialize new node
			v->next = w;         w->prev = v;       //point targets to new node
			v->prev = u;         u->next = v;       //point new node to targets
			n++;
		}
		void insertFront(const T& e) { insert(begin(), e); }
		void insertBack(const T& e) { insert(end(), e); }
		
		//deletions
		void erase(const Iterator& p) {
			//targets
			Node* v = p.v;
			Node* w = v->next;
			
			//repoint
			Node* u = v->prev;
			u->next = w; w->prev = u;
			
			//clean
			delete v;
			n--;
		}
		void eraseFront() { erase(begin()); }
		void eraseBack() { erase(--end()); }
		
		//ADDING THESE METHODS FORMS A SEQUENCE
		Iterator atIndex(int i) const {
			Iterator p = begin();
			
			//increment i times
			for (int j = 0; j < i; j++) ++p;
			return p;
		}
		int indexOf(const Iterator& p) const {
			Iterator q = begin();
			int j = 0;
			
			//increment until theres a match
			while (q != p) {
				++q; ++j;
			}
			return j;
		}
	private:
		int n;
		Node* header;
		Node* trailer;
};
using namespace std;

class AllKinds {
	private:
		int i;
		long l;
		float f;
	public:
		//Constructor
		AllKinds(int a, long b, float c) {
			i = a;
			l = b;
			f = c;
		}
		
		//Getters
		int getInt() { return i; }
		long getLong() { return l; }
		float getFloat() { return f; }
		
		//Setters
		void setInt(int a) { i = a; }
		void setLong(int b) { l = b; }
		void setFloat(int c) { f = c; }
		
		//Sums
		int i_l() { return long(i)+l; }
		int i_f() { return float(i)+f; }
		int l_f() { return float(l)+f; }
		int all() { return float(i)+float(l)+f; }
};
// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )
#define REPALL(i,n) for ( auto &i: n )
#define debuger cout << "111\n"
#define MEM(n,i) memset ( n, i, sizeof n )
#define endl '\n'

// define pair
typedef pair < LL, LL > pll;
typedef pair < int, int > pii;
#define F first
#define S second
#define mp make_pair

// define vector && some stl's api
template < class T > using vec = vector < T >;
typedef vec < int > vi;
typedef vec < LL > vl;
#define pb push_back
#define ep emplace_back
#define REV reverse
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) BEG ( n ), END ( n )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'
#define GETDATA(data,n) RSZ ( data, n ); REPALL ( i, data ) cin >> i

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) ( n.find ( Index ) != n.end() )

// graph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T, vec < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 100005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

/*
                                                                                  ```....``                                                                               
                                                                       `-:/+osyyhhhhhhhhhhhhyso/:.`                                                                       
                                                                 .:/oyhhhhyyyyyyyyyyyyyyyyyyyyyyyyhyo/:.                                                                  
                                                            .:+shhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhys/-`                                                             
                                                        -/oyhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyys/-                                                          
                                                    ./shhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo:`                                                      
                                                 ./shyyyyyyyyyyyyyyyyyyyyyyysso++/::--......-://+osyyyyyyyyyyyyyyyyys:`                                                   
                                              `:syyyyyyyyyyyyyyyyyyyyyso+/-.```                  ``.-:+ossyyyyyyyyyyyyyo:`                                                
                                            -os+/yyyyyyyyyyyyyyyss+/-.`                                 ``-:+osyyyyyyys/+so-                                              
                                         `:so/:-/syyyyyyyyyyso/:.`                                           ``-/+syyyyo::/os/`                                           
                                       `/so:---:syyyyyyyys+:``                `.-::::::::::::::---.`              `-/osys+:::+so-                                         
                                     `/so:---:+syyyyyso/.`             `.-:///:-.`````       ````..-:/::-.`          `.:+ssssosyhs-                                       
                                   `/yy+///+ossyyyyo/.`            .-://-.``      .o+-      `+o/`     ``.-:/:-.          `-+syyyyyhs:                                     
                                  :yhyyysssyyyyys+-`           `-:/:.`   -/.     :o:-++.   :o/.:o:`   -+o:  `.-/:-.         .:osyyyyhs:                                   
                                .ohyyyyyyyyyyys/.           .://-.     `++:++:..o/.```-+/-o/.```.:o::o/-.++`    `-:/:-        `.+syyyyhs-                                 
                               /yyyyyyyyyyyys/.          `://.``++/:` .o/.```-:/-```````-/-````````::.````:o- `-+++``-/:-`       ./syyyyho.                               
                             .shyyyyyyyyyys+.         `-//-`  .o:.-:/+o-`````.`````````````````````````````.+++:../o.  `-//-`      `:oyyyhy/                              
                            :yyyyyyyyyyyso-         .:+/+:.  :+.````````````.:.``````````````````````````````.`````-o:  ./:-/:.      `:syyyhs.                            
                          `+hyyyyyyyyyys:`        -//..o::/++/``````````````-/:```````````````````````````.`````````.+++/-o: .:/-`     `/syyyh:                           
                         `ohyyyyyyyyys/`       `-+/. :o-````.```````````.```-//-`..```````````````````````+.``````````.````+/` `-//.     .+syyh+`                         
                        .shyyyyyyyys+.       `-+o:``++``````````````````:.``-///.--```````````````````````:s````````````````/o../:.//.     -oyyhs.                        
                       .yhyyyyyyyys-        -+:/o:/+:``````````````````/+-``-///:-:```````````````````````.h/````````````````-+/-/o.`//.    `+syhy.                       
                      .yyyyyyyyys+`       -+/`/o.``````````````````````oo:``-//////-```````````````````````y+-````````.```````````-o/`.+/`    :syhh.                      
                     .yhyyyyyyys/`      `++``++````````````..``````````ys/-`-//////:```````````````````````h.o`````````-.```````````:o/++o-    .oyhh.                     
                    `yhyyyyyyys:       :o++/+/```````````./.``````````-oy/:`.///////.``````````````````````h`+-```````/`--.```````````:``.+/`   `oyhy.                    
                   `shyyyyyyys:      .o+..`..```````````-o-..`````````o.o+/-`///////:````````````-````````.h -o```````o/`./+``````````````.:o`   `oyhy`                   
                   ohyyyyyyys:      :o:.```````````````:o:-.``./.````:+`:h//.:///////-```````````s````````:y-.y```````/-+`./o```````````````-o.   `oyho                   
                  /hyyyyyyys:     `+o..```````````````-s/-.``:o+````.s::.oo/:-////////``````````-s:```````o:`-y:.`````-/.o`-+o```````````````-o-   .syd/                  
                 -dyyyyyyyy/     `o/..```````````````.s/:.`:/:+```.:s:`  `s//:////////:`````````o-+```````y`  +/-::-.`.o -o`-+o```````````````.s.   :syh.                 
                `yhyyyyyyyo     `s/.`````````````````o+:-:/..o-::::s-     .s///////////-```````-h`o``````//   /:```--:/s.`//`:o+```````````````.s.   oyhs                 
                +hyyyyyyys.    `s:.`````````````````-y/++:-/o:-.`.+.       ./+++++////++:.----:o/ o--...-+`   //------:+..`s.-/s-```````````````-o`  .syd:                
               .dyyyyyyys:    `s:.``````````````````os/.`` /////:-`          ``..---::::----..``  `......     `..-.--..`   .::+oy````````````````:+   /yhh/`              
               sdyyyyyyyo     o/.``````````:````````y`                                                                          +/````````````````+:  `sydhy-             
              :hyyyyyyys.    /o.```````````+-``````.s                                                                           .y```````:````````.y   /yhhyho.           
            .ohyyyyyyyy+    .y.````````````:+``````:o                                                                            y.`````-/`````````y-  .sydyyyh/          
           /hyyyyyyyyyy-    o/.`````````````y.`````:+                                                                            +:`````o.`````````o+   oydyyyyhs.        
         `shyyyyyyyyyyo    .y.``````````````:s`````:o`ooooooooo+++//::-.`````                              ```.--:::///++++++/-  //````.s``````````/s   /yhhyyyyyh:       
        -hhyyyyyyyyyyy/    +o-```````````````++````-s-ddddddddddddddddddddhyy/                            /yhdddddddddddhhhhhho  /+````s-``````````-y   .yydyyyyyyh+      
       :hyyyyyyyyyyyyy-    y//````````````````++```.y ```````....--::/+hdddddo                            /hdddh+-.`````         //```o:```````````.h`  `sydyyyyyyyho`    
      /dyyyyyyyyyyyyys`   .s:+`````````````````/o.``s`             `/sdddds/`               `      `        -/sdddho:`           o-``o:`````````````h`   oyhhyyyyyyyhs    
     /dyyyyyyyyyyyyyyo    :+/+``````````````````.o:`//          `/sdddho:`           `    ``      `      `     `-+ydddy/.       `y`-o-`````````-````y.   /yhhyyyyyyyyho   
    /dyyyyyyyyyyyyyyy+    //+/````````````````````++-o       `:sdddho:`                  ``      `      `          ./sdddy/.    -+/o``````````::````o/   :yhhyyyyyyyyyh+  
   :dyyyyyyyyyyyyyyyy/    +/s-````````````````````:/`-`   `-ohddds:`               .-:-.`      ``  `-::::.            `:ohddy/` :-`o``````````s`````-y   :yhdyyyyyyyyyyd- 
  -dyyyyyyyyyyyyyyyyy/    /oy``````````````````````y`   -+hddds/`               `////.-+//+:`    -+s:./:.oo`             `-ohdo   `s`````````/+``````y:  :yydyyyyyyyyyyyy`
 `yhyyyyyyyyyyyyyyyyy+    -d+``````````````````````+:  -hddy/.`                 o++/://:/+:/o/:/+++::/::/::s`         ```````.`   -o````````-s```````-y` /yhdyyyyyyyyyyyh/
 +dyyyyyyyyyyyyyyyyyyo    `h.``````````````````````.y`  -/.````````````````    -o::::::::::::::::::::::::::y-   ``````````````````s-```````-s.````````+s oyhhoyhyyyyyyyyh+
`dyyyyyyyyyyyyyyyyyyys    ++````````````````````````:s` `````````````````````` :+::::::::::::::::::::::::::y.  ``````````````````:o```````/o```````````oossdo `.:+syhyyhy.
-dyyyyyyyyyyyyyyhyyyyy.  -s``````````````````````````/o``````````````````````` `s::::::::::++/:-:/+/::::::/o   `````````````````-y.`````.o/``./:````````+hyd-      ``..`` 
 oyhhhhyyyso+/:-hyyyyy/ .y.`````````.-`````--`````````+o`````````````````````   -++/::///+/.`     `://////:`     ``````````````-s-`````/+.`````-//:``````:yh`             
  ````````      ohyyyys.s-`````````:+```````-/-````````/o.````````````````       ``-:--.``           `````                    -o.```./+-`````````.-s+:-```.+o.            
                .dyyyyys.````````:+:``````````:+:.``````-o-````````                                                         `//```:+/.`````````````h`.:so/:--//-`         
                 shyyyo.``````.:s:``````````````-//:.````.+/`                                                             `-/-.-:sh:`.````````````:s  `syd:-://++-        
                 -dys:`````.://-o.`````````````.-``-/++:-.`-/:`                                                           `.````/h:`.:````````````s/  +yho                
                 .o/.`.-:+/:.`  -+``````````````:.````+/-:///+o/-`                                                            `oy-``:.```````````.h` -syy`                
               .//:+sssyyy:      y.`````````````.:````.s`  ```````                                                           -y+.``-:````````````o+ `syh.                 
                   `yhyyyys-     :o``````````````--````sh/.                                                                .os:```-/.``.````````:y``+yh-                  
                    `shyyyys-     o:``````````.```:.```-hyy+.                                                            .+s/````-/:``-.```````.y- /yy-                   
                     `ohyyyys-    `s-`````````--``.:-```+o-oys:.                                                      `-+o:.````-/:``--````````s+`/hs.                    
                       :yyyyys:    .s-`````````:-``-/-```s: `:oso:`      ``                                  `     `-/s/-``````://-`-:`..`````oo.+y/`                     
                        .+yyyys/`   .o:`````````::.`-/-``.s:   .:oso:.``:++:`     .:`      ..       ./.    `/+/..-/+:-s``````.://:.:/.`o.````oo:so.                       
                          ./yyyyo.   `+/````````.::.`-/:.`.s:     `-+ooso-.:+-``-/:-o:   `/+++.   `:o-+/``:o/-+o:-.  /:`.-``.:///-:/-`/y```.ssos-                         
                            `syyys/`   /+.```-/```:/:.-//-..s:        `-/+ooohss/-```++.:+-  -+/.-o/..-+o/+:-.`     .o`:+/`-////://-`/s+``-yhs:`                          
                             o/-+yhs:`  .+/```s+.``-:/:://:-.o+`           `.-:/++++++oss/::::/sso/-...``          `o:/-+::///////:.//o.`+hh-                             
                             o:``.:oys:`  -+-`-o+:``.://////:-/o.                     `````  ```./+.              .so/``y////////:-+://-o//o                              
                             y-`````.:oo+:.`:/-:+:+/.`-://////:/s/`                      `..`     :y            `:s+.  +o//+o///:+s+ss++.`/o                              
                            `h``````````-/+o+//+/o--/+:.-:///os+/oo:`                  `+///++    .y            .-`   :s/+os+//oyyoyy/.```/o                              
                            :o``````````````-/+osyho--:/+/:///+soo+oo:`                `++/++/   -s-                 -s+so+o/+/:..--``````-y                              
                            s:```````````````....-:/+oooossyyysssso:-:.                  ``.``.:+/.           ```.-:+yssos+::``````````````h.                             
                           -y```````````````............--:://+++oosyo+///::::::::://++++++++oss+///::::::/+oo++++//:-.......``````````````o+                             
                           s:```````````````.......................:y```..---------..+:.```   .+` ``````````-s................`````````````-h`                            
                          /s```````````````........................:hs/.`             :/.````.o`            `y................``````````````o/                            
                         .y.````..````````...............:........ohyyyyso/-``       `//y++++y:/`      `.:+oyy/....--..........`````````````.h.                           
                        `s/````:s`````````.............../......-yyyyyyyyyyyyso+:.``  ..-+++o/..  `.:+oyyyyyyyho..../..........``````````-```:y`                          
                        o+````+oo````````../............+-.....:yyyyyyyyyyyyyyyhooss+::o--s+o`:/:oys+oyyyyyyyyyys-..::..........`````````:+```+o                          
                       +o```-o-+/```````../o...........:+.....:hyyyyyyyyyyyyyyyy::yyyyyyo::h-:oyyyyy::yyyyyyyyyyyy-..o...........-````````os.``o+                         
                      +o``.++` y.``````..:h-...........s-....:hyyyyyyyyyyyyyyyh+:+hyyyyyyyyhydhhyyyh+:/hyyyyyyyyyyy-.//..........+-````````yo/``o+                        
                    `s/`.+o.  :o``````..-ho...........+/....-hyyyyyyyyyyyyyyyyy::yyyyyyhhhhdhhhyyyyyy::syyyyyyyyyyyy..+-..........o-```````-s:o-`++                       
                   -s--++.    y-`````..-ys-........../o.....yyyyyyyyyyyyyyyyyyo::hyyyyyydhhyyyyyyyyyh/:/hyyyyyyyyyyhs.:/-.........-y:```````/+`/o./s`                     
                 .oo++/`     :o`````..-y:o..........:+:....+hyyyyyyyyhyyyyyyyh/:+hyyyyyyyyyyyyyyyyyyho::yyyyhyyyyyyyh+.//..........:h/```````+/ `+o/s:                    
               .oh+/.       `y.```...:y.s-.........-/+....-hyyyyyyyyyhyyyyyyyh::ohyyyyyyyyyyyyyyyyyyyy::oyyyhyyyyyyyyh-.//..........+y+```````o:  `/+so.                  
             `--`           s:```.../s`//.........-/+.....syyyyyyyyyyhyyyyyyyy::syyyyyyyyyyyyyyyyyyyyh/:/hyyyhyyyyyyyyy.:-/..........+oo-``````o/    `:+/`                
*/

// |___|___|___|
// 1...l...r...n
// |___|___||___|___|
// 1...l...rl..r...n

struct node {
	node *l, *r;
	int sz, rev;
	char value;

	node ( char );
	node ( node *o );

	inline void up ( void );
	inline void down ( void );
};

node::node ( char _val ) {
	l = r = nullptr;
	sz = 1, rev = 0;
	value = _val;
}

node::node ( node *o ) {
	l = o -> l, r = o -> r;
	sz = o -> sz, rev = o -> rev;
	value = o -> value;
}

inline void node::up ( void ) {
	sz = 1;
	if ( l )
		sz += l -> sz;
	if ( r )
		sz += r -> sz;
}

inline void node::down ( void ) {
	if ( rev ) {
		swap ( l, r );
		if ( l )
			l -> rev ^= 1;
		if ( r )
			r -> rev ^= 1;
		rev = 0;
	}
}

inline int Size ( node *o ) {
	return o ? o -> sz : 0;
}

node *merge ( node *a, node *b ) {
	if ( !a || !b )
		return a ? a : b;
	if ( rand() % ( Size ( a ) + Size ( b ) ) < Size ( a ) ) {
		a -> down();
		a = new node ( *a );
		a -> r = merge ( a -> r, b );
		a -> up();
		return a;
	}
	b -> down();
	b = new node ( *b );
	b -> l = merge ( a, b -> l );
	b -> up();
	return b;
}

void split ( node *o, node *&a, node*&b, int k ) {
	if ( !o ) {
		a = b = nullptr;
		return;
	}

	o -> down();
	o = new node ( *o );
	if ( Size ( o -> l ) < k ) {
		a = o;
		split ( o -> r, a -> r, b, k - Size ( o -> l ) - 1 );
		a -> up();
	}
	else {
		b = o;
		split ( o -> l, a, b -> l, k );
		b -> up();
	}
	o -> up();
}

inline void print ( node *o ) {
	if ( !o )
		return;
	o -> down();
	print ( o -> l );
	cout << o -> value;
	print ( o -> r );
}

int main() {
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	node *root = nullptr, *swp, *l, *r, *mid;
	int n, m, type, L, R, tms;
	char c;
	cin >> tms;
	while ( tms-- ) {
		root = nullptr;
		cin >> n >> m;
		for ( int i = 0 ; i < n ; i++ ) {
			cin >> c;
			root = merge ( root, new node ( c ) );
		}
	
		while ( m-- ) {
			cin >> type >> L >> R;
			if ( type == 1 ) {
				split ( root, swp, r, R );
				split ( swp, l, mid, L - 1 );
				print ( mid );
				cout << endl;
				root = merge ( merge ( l, mid ), r );
			}
			else if ( type == 2 ) {
				split ( root, swp, r, R );
				split ( swp, l, mid, L - 1 );
				root = merge ( merge ( l, mid ), merge ( mid, r ) );
			}
			else if ( type == 3 ) {
				split ( root, swp, r, R );
				split ( swp, l, mid, L - 1 );
				if ( mid )
					mid -> rev ^= 1;
				root = merge ( l, merge ( mid, r ) );
			}
		}
	}
}

// Compile Standard: C++11
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
#define maxN 1005

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

typedef pair < int, pii > PPT;
typedef pair < pii, pii > PPTENSHI;

struct edgeNode{
	int id, s, t;
};

map < int, string > lib;
map < pii, int > table;
pii nodes[maxN];
edgeNode st[maxN][2];
vector < pii > edges[maxN], sst;
bitset < maxN > pushed;
vector < int > mst[maxN];
vector < PPTENSHI > ans, mustAdd;
int idx, cnt, mi = INF, X = -1, Y = -1;

// disjoint set and unit
struct dsu{
	int dis[maxN], sz[maxN];

	// init disjoint set
	inline void init ( int n ) {
		for ( int i = 0 ; i < n + 5 ; i++ )
			dis[i] = i, sz[i] = 1;
	}

	// find function in disjoint set
	int find ( int n ) {
		return dis[n] == n ? n : dis[n] = find ( dis[n] );
	}

	// check two nodes if they are already in the same block or not
	inline bool same ( int a, int b ) {
		return find ( a ) == find ( b );
	}

	// Unit two nodes and their subtree
	inline void Union ( int a, int b ) {
		if ( same ( a, b ) )
			return;
		a = find ( a ), b = find ( b );
		dis[a] = b;
		sz[b] += sz[a];
	}
} dis;

struct segment {
	int seg[maxN << 2];

	void update ( int l, int r, int index, int value, int n ) {
		if ( l == r )
			seg[n] = value;
		else{
			int mid = ( l + r ) >> 1, leftSon = n << 1, rightSon = leftSon | 1;
			if ( index <= mid )
				update ( l, mid, index, value, leftSon );
			else
				update ( mid + 1, r, index, value, rightSon );

			seg[n] = seg[leftSon] + seg[rightSon];
		}
	}

	inline void init ( void ) {
		memset ( seg, 0, sizeof seg );
	}
} seg1[maxN], seg2[maxN];

inline void initSegmentTree ( int n ) {
	for ( int i = 0 ; i < n ; i++ ) {
		seg1[i].init();
		seg2[i].init();
	}
}

// Prim algorithm, for finding minimal spanning tree
inline void Prim ( int n ) {
	dis.init ( n );
	MinHeap < PPT > pq;
	for ( auto i: edges[0] )
		pq.push ( PPT ( i.S, pii ( i.F, 0 ) ) );
	pushed[0] = true;
	while ( dis.sz[dis.find ( 0 )] != n ) {
		PPT top = pq.top();
		pq.pop();
		while ( !pq.empty() && dis.same ( top.S.F, 0 ) ) {
			top = pq.top();
			pq.pop();
		}

		int u = top.S.F, v = top.S.S;

		mst[u].pb ( v );
		mst[v].pb ( u );
		dis.Union ( u, v );

		if ( !pushed[u] ) {
			for ( auto i: edges[u] )
				pq.push ( PPT ( i.S, pii ( i.F, u ) ) );
			pushed[u] = true;
		}
		if ( !pushed[v] ) {
			for ( auto i: edges[v] )
				pq.push ( PPT ( i.S, pii ( i.F, v ) ) );
			pushed[v] = true;
		}
	}
}

// find all Steiner point for all edges on minimal spanning tree
void dfs ( int n, int p ) {
	for ( auto i: mst[n] ) {
		if ( i == p )
			continue;
		if ( nodes[n].F != nodes[i].F && nodes[n].S != nodes[i].S ) {
			nodes[cnt] = pii ( nodes[n].F, nodes[i].S );
			st[idx][0] = edgeNode { cnt++, n, i };
			nodes[cnt] = pii ( nodes[i].F, nodes[n].S );
			st[idx++][1] = edgeNode { cnt++, n, i };
		}
		else
			mustAdd.pb ( mp ( nodes[i], nodes[n] ) );
		dfs ( i, n );
	}
}

// calculate Steiner distent
inline int calc ( vector < PPTENSHI > ed ) {
	int res = 0;
	initSegmentTree ( cnt + 5 );

	for ( auto i: ed ) {
		pii u = i.F, v = i.S;
		if ( u.F == v.F ) {
			int s = min ( u.S, v.S ), t = max ( u.S, v.S );
			for ( int j = s ; j < t ; j++ )
				seg2[u.F].update ( 0, Y, j, 1, 1 );
		}
		else {
			int s = min ( u.F, v.F ), t = max ( u.F, v.F );
			for ( int j = s ; j < t ; j++ )
				seg1[u.S].update ( 0, X, j, 1, 1 );
		}
	}
	for ( int i = 0 ; i <= Y + 1 ; i++ )
		res += seg1[i].seg[1];
	for ( int i = 0 ; i <= X + 1 ; i++ )
		res += seg2[i].seg[1];
	return res;
}

// for all Steiner point combination
void Steiner ( int id, vector < PPTENSHI > ed ) {
	if ( id == idx ) {
		int swp = calc ( ed );
		if ( mi > swp ) {
			mi = swp;
			ans = ed;
		}
		return;
	}
	int u = st[id][0].t, v = st[id][0].s;
	for ( int i = 0 ; i < 2 ; i++ ) {
		ed.pb ( mp ( nodes[u], nodes[st[id][i].id] ) );
		ed.pb ( mp ( nodes[v], nodes[st[id][i].id] ) );
		Steiner ( id + 1, ed );
		ed.pop_back();
		ed.pop_back();
	}
}

// build Steiner Tree in standard format
inline void build ( void ) {
	vector < pii > libX[maxN], libY[maxN];
	for ( auto j: ans ) {
		int u = table[j.F], v = table[j.S];
		if ( nodes[u].F == nodes[v].F ) {
			if ( nodes[u].S > nodes[v].S )
				swap ( u, v );
			int idx = -2, x = nodes[u].F, sz = libX[x].size();
			if ( libX[x].empty() ) {
				libX[x].pb ( pii ( u, v ) );
				continue;
			}
			for ( int i = 0 ; i < sz ; i++ ) {
				idx = -2;
				if ( libX[x][i].F == u ) {
					if ( nodes[v].S < nodes[libX[x][i].S].S ){
						libX[x].pb ( pii ( libX[x][i].F, v ) );
						libX[x].pb ( pii ( v, libX[x][i].S ) );
						idx = i;
					}
					else {
						libX[x].pb ( pii ( libX[x][i].S, v ) );
						idx = -1;
					}
					break;
				}
				else if ( libX[x][i].S == v ) {
					if ( nodes[libX[x][i].F].S < nodes[u].S ) {
						libX[x].pb ( pii ( libX[x][i].F, u ) );
						libX[x].pb ( pii ( u, libX[x][i].S ) );
						idx = i;
					}
					else {
						libX[x].pb ( pii ( u, libX[x][i].F ) );
						idx = -1;
					}
					break;
				}
			}

			if ( idx == -2 )
				libX[x].pb ( pii ( u, v ) );
			else if ( idx != -1 )
				libX[x].erase ( libX[x].begin() + idx );
		}
		else if ( nodes[u].S == nodes[v].S ) {
			if ( nodes[u].F > nodes[v].F )
				swap ( u, v );
			int idx = -2, y = nodes[u].S, sz = libY[y].size();
			if ( libY[y].empty() ) {
				libY[y].pb ( pii ( u, v ) );
				continue;
			}
			for ( int i = 0 ; i < sz ; i++ ) {
				idx = -2;
				if ( libY[y][i].F == u ) {
					if ( nodes[v].F < nodes[libY[y][i].S].F ) {
						libY[y].pb ( pii ( libY[y][i].F, v ) );
						libY[y].pb ( pii ( v, libY[y][i].S ) );
						idx = i;
					}
					else {
						libY[y].pb ( pii ( libY[y][i].S, v ) );
						idx = -1;
					}
					break;
				}
				else if ( libY[y][i].S == v ) {
					if ( nodes[libY[y][i].F].F < nodes[u].F ) {
						libY[y].pb ( pii ( libY[y][i].F, u ) );
						libY[y].pb ( pii ( u, libY[y][i].S ) );
						idx = i;
					}
					else {
						libY[y].pb ( pii ( u, libY[y][i].F ) );
						idx = -1;
					}
					break;
				}

				if ( idx == -2 )
					libY[y].pb ( pii ( u, v ) );
				else if ( idx != -1 )
					libY[y].erase ( libY[y].begin() + idx );
			}
		}
		else
			cout << "NANI?!\n";
	}

	for ( int j = 0 ; j <= X ; j++ )
		for ( auto i: libX[j] )
			sst.pb ( i );

	for ( int j = 0 ; j <= Y ; j++ )
		for ( auto i: libY[j] )
			sst.pb ( i );
}

// itoa, int to string
inline string itoa ( int n ) {
	string res = "";
	while ( n ) {
		res += char ( '0' + n % 10 );
		n /= 10;
	}
	reverse ( res.begin(), res.end() );
	return res;
}

// main function
int main() {
	// io buff
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	ifstream input;
	ofstream output;
	input.open ( "input.txt" );
	output.open ( "output.txt" );
	int n = 0, x, y;
	string name;

	// get input data
	input >> name >> n;
	for ( int i = 0 ; i < n ; i++ ) {
		input >> name >> x >> y;
		lib[i] = name;
		nodes[i] = pii ( x, y );
		table[nodes[i]] = i;
	}
	input.close();

	// build the graph
	for ( int i = 0 ; i < n ; i++ )
		for ( int j = i + 1 ; j < n ; j++ ) {
			int dist = abs ( nodes[i].F - nodes[j].F ) + abs ( nodes[i].S - nodes[j].S );
			edges[i].pb ( pii ( j, dist ) );
			edges[j].pb ( pii ( i, dist ) );
		}

	// build minimal spanning tree
	Prim ( n );

	// find all Steiner poing
	idx = 0, cnt = n;
	dfs ( 0, 0 );

	// find smallest Steiner tree
	for ( int i = 0 ; i < cnt ; i++ ) {
		X = max ( X, nodes[i].F );
		Y = max ( Y, nodes[i].S );
	}

	Steiner ( 0, mustAdd );

	set < pii > op;
	for ( auto i: ans ) {
		op.insert ( i.F );
		op.insert ( i.S );
	}
	for ( int i = 0 ; i < n ; i++ )
		op.erase ( nodes[i] );

	// output nodes
	output << "NumVerties: " << n << '\n';
	for ( int i = 0 ; i < n ; i++ )
		output << lib[i] << '\t' << nodes[i].F << '\t' << nodes[i].S << '\n';
	// mark used Steiner point
	int swp = 0;
	for ( auto i: op ) {
		name = "S" + itoa ( ++swp );
		output << name << '\t' << i.F << '\t' << i.S << '\n';
		int idx = -1;
		for ( int j = 0 ; j < cnt ; j++ )
			if ( nodes[j] == i ) {
				idx = j;
				break;
			}
		
		lib[idx] = name;
		table[i] = idx;
	}

	// transform
	sort ( ans.begin(), ans.end() );
	ans.erase ( unique ( ans.begin(), ans.end() ), ans.end() );
	build();

	// output edges
	sort ( sst.begin(), sst.end() );
	sst.erase ( unique ( sst.begin(), sst.end() ), sst.end() );
	output << "\nNumEdges: " << sst.size() << endl;
	swp = 0;
	for ( auto i: sst )
		output << 'E' << itoa ( ++swp ) << '\t' << lib[i.F] << '\t' << lib[i.S] << endl;

	output << "\nWireLength: " << mi << endl;

	output.close();
}

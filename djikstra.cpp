void dijkstra(Graph g, int *dist, int *prev, int start) {
   int n = g.n;

   for(int u = 0; u<n; u++) {
      dist[u] = 9999;   //set as infinity
      prev[u] = -1;    //undefined previous
   }

   dist[start] = 0;   //distance of start is 0
   set<int> S;       //create empty set S
   list<int> Q;

   for(int u = 0; u<n; u++) {
      Q.push_back(u);    //add each node into queue
   }

   while(!Q.empty()) {
      list<int> :: iterator i;
      i = min_element(Q.begin(), Q.end());
      int u = *i; //the minimum element from queue
      Q.remove(u);
      S.insert(u); //add u in the set
      list<node> :: iterator it;

      for(it = g.adjList[u].begin(); it != g.adjList[u].end();it++) {
         if((dist[u]+(it->cost)) < dist[it->dest]) { //relax (u,v)
            dist[it->dest] = (dist[u]+(it->cost));
            prev[it->dest] = u;
         }
      }
   }
}
struct Set
{
  void init(bool (*eq)(TipoValue,TipoValue),bool (*lt)(TipoValue,TipoValue));               // funzione di inizializzazione.
  int size();                // restituisce la cardinalità dell'insieme.
  bool full();               // restituisce TRUE se è pieno.
  bool empty();              // restituisce TRUE se è vuoto.
  void clear();              // cancella tutti gli elementi
  void add(TipoValue el);    // aggiunge  l'elemento el
  void remove(TipoValue el); // elimina l'elemento el
  bool member(TipoValue el); // restituisce TRUE se el è presente.
  void show();

private:
  TipoValue *v;
  int n, len;
  void ins(TipoValue val, int pos);
  void elim(int i); // funzione di eliminazione
  void change_dim(float f);
  bool search_bin(int el);
  bool (*eq_fptr)(TipoValue a, TipoValue b);
  bool (*lt_fptr)(TipoValue a, TipoValue b);
};

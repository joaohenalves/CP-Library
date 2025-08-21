#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>


//LEMBRANDO QUE ISSO É UM SET
//SE PRECISAR SER UM MULTISET, TEM QUE MUDAR O COMPARADOR PARA LESS_EQUAL
//OU CADA ELEMENTO SER UM PAR
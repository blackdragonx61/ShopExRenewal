///Add if not exist
#include "service.h"

//Find
typedef struct SShopItemTable

///Add Above
#if defined(ENABLE_RENEWAL_SHOPEX)
enum STableExTypes
{
	SHOPEX_GOLD = 1,
	SHOPEX_SECONDARY,
	SHOPEX_ITEM,
	SHOPEX_EXP,
	SHOPEX_MAX,
};
#endif

//Find in typedef struct SShopItemTable
	BYTE		display_pos;
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	long	alSockets[ITEM_SOCKET_MAX_NUM];
	TPlayerItemAttribute	aAttr[ITEM_ATTRIBUTE_MAX_NUM];
	BYTE 	price_type;
	DWORD 	price_vnum;
	SShopItemTable() : price_type(SHOPEX_GOLD), price_vnum(0) {
		memset(&alSockets, 0, sizeof(alSockets));
		memset(&aAttr, 0, sizeof(aAttr));
	}
#endif

//Find in typedef struct SShopTable
	TShopItemTable	items[SHOP_HOST_ITEM_MAX_NUM];
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	char szShopName[SHOP_TAB_NAME_MAX + 1];
#endif
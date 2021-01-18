//Find in : typedef struct packet_shop_item
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	BYTE 	price_type;
	DWORD 	price_vnum;
#endif

///Add
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
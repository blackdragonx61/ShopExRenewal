//Find
	bool		InitializeShopTable();
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	bool		InitializeShopEXTable();
#endif

//Find
	TShopTable* m_pShopTable;
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	TShopTable*			m_pShopEXTable;
	int					m_iShopEXTableSize;
#endif
//Find
	m_pShopTable(NULL),
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	m_iShopEXTableSize(0),
	m_pShopEXTable(NULL),
#endif

//Find
		sizeof(WORD) + sizeof(WORD) + sizeof(TShopTable) * m_iShopTableSize +
		
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
		sizeof(WORD) + sizeof(WORD) + sizeof(TShopTable) * m_iShopEXTableSize +
#endif

//Find
	peer->EncodeWORD(sizeof(TShopTable));
	peer->EncodeWORD(m_iShopTableSize);
	peer->Encode(m_pShopTable, sizeof(TShopTable) * m_iShopTableSize);
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	peer->EncodeWORD(sizeof(TShopTable));
	peer->EncodeWORD(m_iShopEXTableSize);
	peer->Encode(m_pShopEXTable, sizeof(TShopTable) * m_iShopEXTableSize);
#endif
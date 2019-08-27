#Find
				self.middleRadioButtonGroup.OnClick(0)
			
#Change
				#Fix for tabs
				if app.ENABLE_RENEWAL_SHOPEX:
					self.middleRadioButtonGroup.OnClick(0)
				else:
					self.middleRadioButtonGroup.OnClick(1)
#Find
	def OverInItem(self, slotIndex):
	
#Change func
	def OverInItem(self, slotIndex):
		slotIndex = self.__GetRealIndex(slotIndex)
		if mouseModule.mouseController.isAttached():
			return

		if 0 != self.tooltipItem:
			if app.ENABLE_RENEWAL_SHOPEX:
				PriceType = shop.GetItemPriceType(slotIndex)
				if PriceType == 1:
					self.tooltipItem.SetShopItem(slotIndex)
				elif PriceType == 2:
					self.tooltipItem.SetShopItemBySecondaryCoin(slotIndex)
				else:
					self.tooltipItem.SetShopItemByShopEx(slotIndex, PriceType)
			else:
				if shop.SHOP_COIN_TYPE_GOLD == shop.GetTabCoinType(self.tabIdx):
					self.tooltipItem.SetShopItem(slotIndex)
				else: 
					self.tooltipItem.SetShopItemBySecondaryCoin(slotIndex)
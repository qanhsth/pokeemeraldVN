LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Chào mừng đến với CỬA HÀNG DƯỢC LIỆU,\n"
	.string "nơi bán thuốc công hiệu mà lại rẻ!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "Con tới để kiếm dược liệu\n"
	.string "NÚI LỬA phải không?\p"
	.string "Rất đáng khen.\p"
	.string "Ta thích con! Cầm lấy!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "Cái CỦI ta đưa con, được dùng\n"
	.string "để làm dược liệu.\p"
	.string "Nó cũng có tác dụng khác nếu\n"
	.string "đưa cho POKéMON cầm.\p"
	.string "Làm tăng ST chiêu thức\n"
	.string "hệ LỬA.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "Dược liệu có hiệu quả rất tốt.\n"
	.string "Mà POKéMON sẽ không ưa đâu.\l"
	.string "Tại vì nó rất là đắng!$"


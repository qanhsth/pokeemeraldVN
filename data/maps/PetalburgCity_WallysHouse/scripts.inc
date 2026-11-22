PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Con là…\n"
	.string "À, con là {PLAYER}, phải không?\p"
	.string "Hồi đó con chơi với QUÝ,\n"
	.string "cô chú rất cảm kích.\p"
	.string "Hồi nhỏ nó yếu lắm,\n"
	.string "bệnh hoài à.\p"
	.string "Rồi chú mới cho nó qua nhà họ\n"
	.string "hàng ở THỊ TRẤN GIẢN ĐƠN.\p"
	.string "Ở đó không khí nó\n"
	.string "trong lành hơn ở đây.\p"
	.string "Con nói sao á? QUÝ đâu?\n"
	.string "QUÝ nó đi rồi luôn hả.\p"
	.string "Không biết giờ\n"
	.string "nó đi đâu rồi nữa?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Không biết giờ QUÝ sao rồi?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}! Xin lỗi vì\n"
	.string "đã lôi con tới đây.\p"
	.string "QUÝ giờ nó rất là khỏe mạnh kể\n"
	.string "từ khi nó tới THỊ TRẤN GIẢN ĐƠN.\p"
	.string "Cô chú cảm ơn con rất nhiều!\p"
	.string "Lúc mà QUÝ nó đi, con có giúp\n"
	.string "nó bắt POKéMON, phải không?\p"
	.string "Chú nghĩ là lúc đó\n"
	.string "QUÝ nó rất là vui.\p"
	.string "Thực ra là không chỉ QUÝ thôi đâu.\n"
	.string "Chú, ba của nó, cũng vui lây.\p"
	.string "Chú cũng mừng vì nó có người\n"
	.string "bạn tuyệt vời như con.\p"
	.string "Chú có cái này muốn cho con,\n"
	.string "con cứ lấy đi, đừng có ngại.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Nếu POKéMON biết xài LƯỚT SÓNG,\n"
	.string "con sẽ có thể du hành khắp nơi.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "QUÝ cũng sắp về rồi.\n"
	.string "Chú mong ngóng quá.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Hả? Con thấy QUÝ ở\n"
	.string "TP.SẮC MÀU hả?\p"
	.string "Trời, {PLAYER}, giỡn chú nữa.\p"
	.string "Nó có thể khoẻ mạnh, nhưng\n"
	.string "với sức của nó thì không thể\l"
	.string "nào đi xa tới vậy được đâu.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "QUÝ nó kể cô chú, lúc mà nó\n"
	.string "bắt được POKéMON, nó rất là vui.\p"
	.string "Cũng lâu dữ lắm rồi mới thấy\n"
	.string "nó cười tươi như vậy.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Cô muốn con giữ bí mật\n"
	.string "mật này với chồng cô…\p"
	.string "QUÝ nó đi khỏi THỊ TRẤN GIẢN\n"
	.string "ĐƠN rồi mà không nói ai hết.\p"
	.string "Nhìn nó yếu vậy thôi, chứ\n"
	.string "nó mạnh mẽ lắm đó.\p"
	.string "Chắc là ngày nào đó nó sẽ\n"
	.string "trở về mạnh giỏi mà thôi!$"

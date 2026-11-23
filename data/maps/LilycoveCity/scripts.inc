LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "PHƯƠNG: Ủa, ê?\n"
	.string "{PLAYER} cũng đi mua sắm nữa hả?\p"
	.string "Tui mới mua 1 đống CÚP BẾ với\n"
	.string "TRANH LỚN.\p"
	.string "Tất nhiên, tui cũng bắt nhiều\n"
	.string "POKéMON rồi, với tui cũng\l"
	.string "đang nuôi tụi nó luôn nè.\p"
	.string "Thực ra, tui sợ là ông nuôi\n"
	.string "POKéMON không kỹ đó, {PLAYER} ơi.\p"
	.string "Nên là tui sẽ thách đấu với ông, để coi\n"
	.string "POKéMON của ông sao rồi nha, {PLAYER}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "PHƯƠNG: Ủa, sao dạ? {PLAYER}, ông\n"
	.string "đang nuôi POKéMON mà phải không?\p"
	.string "NHL POKéMON mà như vậy\n"
	.string "là không có được đâu nha…$"

LilycoveCity_Text_MayBattleMe:
	.string "PHƯƠNG: Thôi, đấu với tui đi, để\n"
	.string "tui coi POKéMON của ông sao rồi!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "PHƯƠNG: POKéMON tui nuôi sao mà thua\n"
	.string "POKéMON của ông được, {PLAYER} ơi!$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Tui nhớ có lần đấu với ông\n"
	.string "trên ĐƯỜNG 103.\p"
	.string "Chắc là trận đó giúp ông\n"
	.string "mạnh lên đúng không, {PLAYER}?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "PHƯƠNG: Chắc tui phải quay về\n"
	.string "THỊ TRẤN MỸ BẠCH thôi.\p"
	.string "Tui cũng bắt đủ POKéMON rồi,\n"
	.string "với DS.POKéMON cũng ok rồi, nên\l"
	.string "tui sẽ về khoe với ba tui.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}, giờ ông tính đi đâu?\p"
	.string "Lấy hết HUY HIỆU rồi vô thách đấu\n"
	.string "LIÊN ĐOÀN POKéMON hả?\p"
	.string "Vậy trong lúc ông lấy HUY HIỆU,\n"
	.string "tui sẽ hoàn thiện DS.POKéMON của\l"
	.string "mình. Chắc sẽ xong trước ông thôi!\p"
	.string "Đi trước nha!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}, giờ ông tính đi đâu?\p"
	.string "Ông tính thách đấu\n"
	.string "LIÊN ĐOÀN POKéMON hả?\p"
	.string "Ha là tính hoàn thiện\n"
	.string "DS.POKéMON?\p"
	.string "Nếu thách đấu thì tui thua, mà\n"
	.string "DS.POKéMON thì tui sẽ xong trước ông!\p"
	.string "Đi trước nha!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER} ơi, giờ ông tính làm gì?\p"
	.string "Ông tính tham gia\n"
	.string "CHIẾN KHU hả?\p"
	.string "Ha là tính hoàn thiện\n"
	.string "DS.POKéMON?\p"
	.string "Nếu thách đấu thì tui thua, mà\n"
	.string "DS.POKéMON thì tui sẽ xong trước ông!\p"
	.string "Đi trước nha!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "DŨNG: Ủa, ê, {PLAYER} phải không?\p"
	.string "Tui đang chạy việc vặt cho ba tui.\n"
    .string "Không, tui không có mua cúp bế.\p"
    .string "À mà, cũng lâu rồi ha.\p"
    .string "Muốn đấu thử để coi ai huấn\n"
    .string "luyện POKéMON giỏi hơn không?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "DŨNG: Ủa, sao vậy?\n"
	.string "Sợ thua hả?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "DŨNG: Muốn đấu thử để coi ai\n"
	.string "huấn luyện POKéMON giỏi hơn không?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "DŨNG: Ủa, bà cũng biết là tui\n"
	.string "sẽ không thua mà, {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Hừm…\n"
	.string "Bà cũng huấn luyện nhiều rồi ha.\p"
    .string "Hơi khó chịu một chút--tại tui đã có\n"
    .string "lợi thế là NHL trước bà rồi…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "DŨNG: Tui…\n"
	.string "Tui tính về lại MỸ BẠCH.\p"
	.string "Bà cũng biết là tui đang phụ ba\n"
	.string "làm DS.POKéMON. Giờ cũng được kha khá\l"
	.string "rồi, nên tui tính đi cho ổng coi thử.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER} ơi, giờ bà tính làm gì tiếp?\p"
	.string "Đi gôm hết HUY HIỆU rồi lại\n"
	.string "LIÊN ĐOÀN POKéMON hay sao?\p"
	.string "Chắc tui cũng phải vậy quá…\p"
	.string "Mà thôi, tui đi nha!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER} ơi, giờ bà tính làm gì tiếp?\p"
	.string "Giờ bà cũng mạnh rồi đó, sao không\n"
	.string "thi đấu LIÊN ĐOÀN POKéMON thử đi?\p"
	.string "Heh, dù có là tui--Nếu luyện POKéMON\n"
	.string "thêm nữa, tui sẽ mạnh lên nhanh thôi\l"
	.string "{PLAYER} ơi.\p"
	.string "Mà thôi, tui đi nha!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER} ơi, giờ bà tính làm gì tiếp?\p"
	.string "Bà có tính tham gia\n"
	.string "CHIẾN KHU không?\p"
	.string "Hay là hoàn thiện\n"
	.string "DS.POKéMON trước?\p"
	.string "Giờ bà cũng mạnh rồi đó, bà cũng\n"
	.string "nên cân nhắc tham gia CHIẾN KHU đi.\p"
	.string "Heh, nếu luyện POKéMON thêm xíu nữa,\n"
	.string "là tui sẽ hạ được bà thôi, {PLAYER} ơi.\p"
	.string "Chắc tui cũng nên lại chỗ\n"
	.string "CHIẾN KHU luôn.\p"
	.string "Mà thôi, tui đi nha!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu…\p"
	.string "Tụi mình vừa mới chuyển đồ\n"
	.string "lại CĂN CỨ, mới bữa nay thôi…\p"
	.string "A-ai vậy?!\n"
	.string "Ta đang nói chuyện một mình mà!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Ta chỉ là thằng CULI, nên ta\n"
	.string "không biết ÔNG TRÙM nghĩ gì đâu…\p"
	.string "Mà được ở ĐỘI AQUA, thì ta biết\n"
	.string "sẽ có cơ hội làm gì đó lớn lớn!\p"
	.string "A-ai vậy?!\n"
	.string "Ta đang nói chuyện một mình mà!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Ê, ê!\p"
	.string "Đừng có lại chỗ cái hang gần vịnh!\p"
	.string "Tại sao? Còn phải hỏi!\n"
	.string "Nói thì nghe đi, nít nét bày đặt!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Nếu cả thế giới thuộc về AQUA,\n"
	.string "thì sẽ trở thành nơi hạnh phúc\l"
	.string "hơn cho POKéMON.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Kia rồi! WAILMER!\n"
    .string "Nhảy lên khỏi mặt nước đi!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hả? Ngươi muốn gì?\p"
	.string "Đừng có cản trở ta tập luyện,\n"
	.string "ngươi, biến đi chỗ khác giùm cái?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Ở đây cũng có\n"
	.string "HỘI THI ĐẤU POKéMON nè.\p"
	.string "Có nghĩa là POKéMON được nuôi kỹ\n"
	.string "sẽ tụ họp lại đây từ khắp vùng miền.\p"
	.string "Trái tim tui tràn ngập niềm phấn khởi!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Bạn có thấy cái hang động kỳ lạ\n"
	.string "ở vịnh ngay góc phố không?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Tui tính dạy cho POKéMON\n"
	.string "mấy chiêu mới để đi THI.\p"
	.string "Bởi vậy tui tính đi gặp ÔNG\n"
	.string "XOÁ CHIÊU để nhờ xoá chiêu HM giùm.$"

LilycoveCity_Text_ImFromKanto:
	.string "Tui đến từ KANTO.\p"
	.string "Vùng HOENN là một nơi đẹp đẽ, xung\n"
	.string "quanh toàn nước, và cỏ xanh tươi.\p"
	.string "Ủa? Khoan cái…\p"
	.string "Hình như có con POKéMON hiếm\n"
	.string "chỉ sống ở đây thì phải?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "ĐỘI AQUA đang huấn luyện cho\n"
	.string "WAILMER ở vịnh nãy giờ đó.\p"
	.string "THUỶ THỦ tụi tui giờ không có\n"
	.string "đi ra ngoài đó được luôn!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ahoy, bạn có biết?\p"
	.string "Có người đá tụi AQUA ra khỏi\n"
    .string "đường đi của tụi mình rồi!\p"
    .string "Và WAILMER rời khỏi vịnh, để\n"
    .string "tụi tui có thể đưa thuyền ra ngoài.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Đang chợp mắt thư giãn tại một nhà\n"
    .string "trọ bên bờ, lắng nghe tiếng sóng vỗ…\p"
    .string "Thì có người lấy mất POKéMON của tui!\p"
    .string "Ai lấy vậy trời?\n"
	.string "Tụi AQUA hả? Không lẽ tụi AQUA?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "POKéMON bị lạc của tui…\n"
	.string "Nó quay lại lúc nào không hay!$"

LilycoveCity_Text_ImArtDealer:
	.string "Ta là người BÁN TRANH.\p"
	.string "Ta mua và bán đủ loại tác phẩm\n"
	.string "nghệ thuật, đặc biệt là tranh.\p"
	.string "Nghe nói BẢO TÀNG ở đây có nhiều\n"
    .string "tác phẩm hay được trưng bày…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Dù chúng ta có già, da nhăn nheo,\n"
    .string "biển sẽ mãi trẻ trung với\l"
    .string "sự rực rỡ tràn đầy sức sống…\p"
	.string "Phừôôôô phừôôôô…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "60 năm trước chồng ta\n"
	.string "đã cầu hôn ta tại đây.\l"
	.string "Biển vẫn đẹp như ngày nào.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Ờm, con có biết về hang động kỳ lạ\n"
    .string "trong vịnh nhỏ này không?\p"
    .string "Vốn dĩ là một công trình tự nhiên,\n"
	.string "nhưng rồi ĐỘI AQUA đó đã\l"
    .string "tới và tiến hành cải tạo lại.\p"
    .string "Họ tự xưng là “ĐỘI AQUA\n"
    .string "yêu thiên nhiên”!\p"
    .string "Nhưng những gì họ làm và những gì họ\n"
    .string "nói hoàn toàn không trùng khớp nhau!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Cái hang trong vịnh đó…\p"
    .string "Lúc đầu tui không để ý,\n"
    .string "giờ nó trống trơn luôn rồi.\p"
    .string "Cái ĐỘI AQUA đó, chắc họ\n"
    .string "đã bỏ đi rồi.$"

LilycoveCity_Text_CitySign:
	.string "TP.BIỂN\p"
	.string "“Nơi tận cùng của mặt đất,\n"
	.string "và sóng biển ngoi lên.”$"

LilycoveCity_Text_ContestHallSign:
	.string "HỘI THI ĐẤU POKéMON\n"
	.string "“Nơi tập hợp nhiều NHL!”$"

LilycoveCity_Text_MotelSign:
	.string "NHÀ TRỌ VỊNH\p"
	.string "“Tụi tui là vịnh của\n"
	.string "TP.BIỂN.”$"

LilycoveCity_Text_MuseumSign:
	.string "BẢO TÀNG TP.BIỂN\p"
	.string "“Triễn lãm Bộ sưu tập\n"
    .string "POKéMON kiệt tác!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "BẢO TÀNG TP.BIỂN\p"
	.string "“Triễn lãm Bộ sưu tập POKéMON\n"
	.string "của {PLAYER}!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "BẾN CẢNG TP.BIỂN\p"
	.string "“Tàu S.S. TIDAL đang được\n"
	.string "thi công ở TP.CẢNG.\p"
	.string "“Dịch vụ tàu sẽ sớm\n"
	.string "được mở.”$"

LilycoveCity_Text_HarborSign:
	.string "BẾN CẢNG TP.BIỂN\p"
	.string "“Tận hưởng chuyến du ngoạn\n"
	.string "trên tàu S.S. TIDAL.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "CLB HÂM MỘ POKéMON\p"
	.string "Tên của mấy NHL được viết\n"
    .string "méo xẹo trên cái bảng…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "TRUNG TÂM MUA SẮM TP.BIỂN\p"
	.string "“Ngập tràn sản phẩm tuyệt vời\n"
    .string "và thú vị!\p"
	.string "“Một nơi phù hợp để\n"
	.string "kiếm thứ bạn cần!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "NHÀ của ÔNG XOÁ CHIÊU\p"
	.string "“Xoá chiêu cho POKéMON.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Bạn có biết\n"
	.string "MÁY XAY TRÁI CÂY không?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Người ta phải hợp tác\n"
	.string "mới quay nhanh lên được.\p"
	.string "Bạn càng quay nhanh, thì được nhiều\n"
	.string "{POKEBLOCK} hơn, nghe nói vậy đó.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Cái này để làm một loại kẹo,\n"
	.string "người ta kêu là {POKEBLOCK}.\p"
	.string "Nếu bạn cho POKéMON ăn {POKEBLOCK},\n"
	.string "thể trạng của nó sẽ tốt hơn nhiều.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Nghe nói có một toà tháp\n"
	.string "ở đâu đó trên đường biển.\p"
	.string "Hình như là CỘT TRỜI thì phải.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Tui thấy cái toà tháp cao\n"
	.string "cao ở vòng vòng ĐƯỜNG 131.\p"
	.string "Có khi nào là…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Tụi tui tới đây để\n"
	.string "hưởng tuần trăng mật.\p"
	.string "Tụi tui có thấy POKéMON\n"
	.string "hệ RỒNG đang lượn lờ trên trời.\p"
	.string "POKéMON ngầu vậy có\n"
	.string "sống ở HOENN hong ta?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Chuyến đi này, tụi tui hứa với nhau\n"
    .string "là phải kiếm được nhiều POKéMON hiếm.\p"
    .string "Bởi vậy, tụi tui mới mừng khi nhìn thấy\n"
    .string "con POKéMON hiếm ngay khi vừa mới tới.\p"
    .string "Ý là, tụi tui thực sự rất hạnh phúc!$"


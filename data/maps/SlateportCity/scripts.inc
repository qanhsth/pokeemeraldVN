SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Ta là THƯƠNG NHÂN! Ta bán\n"
	.string "tất cả những thứ ngươi cần!$"

SlateportCity_Text_OhYourPokemon:
	.string "Ủa?\n"
	.string "{STR_VAR_1} của bạn…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Rất xuất sắc!\p"
	.string "Hãy thưởng cho nó cái này,\n"
	.string "RUY BĂNG CỔ VŨ.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} nhận RUY BĂNG CỔ VŨ.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} để RUY BĂNG CỔ VŨ\n"
	.string "lên {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Bạn phải nỗ lực hơn nữa.\p"
	.string "Thì tui mới cho POKéMON\n"
	.string "của bạn thứ gì đó tốt hơn.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Trời! {STR_VAR_1} của bạn đeo cái\n"
	.string "RUY BĂNG CỔ VŨ nhìn hợp quá!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "Ánh sáng ngọn hải đăng chiếu\n"
	.string "tới đây từ hàng chục dặm.\p"
	.string "Không biết nó có làm POKéMON\n"
	.string "ở dưới biển giật mình không nữa.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Trời ơi, nhìn nè!\p"
	.string "Rong biển ở vòng vòng chỗ này\n"
	.string "rất tươi và tràn đầy sức sống.\p"
	.string "Tại nhìn nó giống như là đang\n"
	.string "rướn lên để tấn công vậy đó!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Chỗ nào nước sạch, thì\n"
	.string "trái cây sẽ bội thu.\p"
	.string "Và khi mà con người tụ họp lại,\n"
	.string "thì phiên chợ sẽ sớm bắt đầu.\p"
	.string "Đó là cách mà thị trấn phát triển.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Đi mua sắm ở nơi mà bạn có thể\n"
	.string "cảm nhận được hương của biển…\p"
	.string "TP.CẢNG là một nơi quá lý tưởng!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Nếu bạn để CÚP BẾ với GỐI trên sàn,\n"
	.string "thì sẽ bị dơ.\p"
	.string "Tui sẽ đi mua mấy cục GẠCH để cho\n"
	.string "CÚP BẾ với GỐI không bị dơ khi mà\l"
	.string "tui để xuống đất.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Wroooar! Tui sẽ tham gia\n"
	.string "HỘI THI ĐẤU luôn!\p"
	.string "Mà phải đi bắt mấy con\n"
	.string "POKéMON cái mới được!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Whew… Đuối ghê…\p"
	.string "Tui mới đi bộ từ TP.HOA TÍM tới đây.\n"
	.string "Nhưng mà thành phố này lớn thiệt.\p"
	.string "Biết vậy nãy đi\n"
	.string "XE ĐẠP cho rồi.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "SANG, cái người xây BẢO TÀNG,\n"
	.string "cũng tình cờ là đội trưởng đội\l"
	.string "khám phá dưới biển.\p"
	.string "Nên người ta kêu là THUYỀN TRƯỞNG SANG.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Đằng đó có chuyện gì vậy?\n"
	.string "Xếp hàng dài luôn…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Hồi còn nhỏ, cô hay đi\n"
	.string "BẢO TÀNG lắm.\p"
	.string "Cô hay mơ về bí ẩn biển sâu\n"
	.string "khi mà được cho coi triển lãm.$"

SlateportCity_Text_QuitPushing:
	.string "Ê, ê! Đừng có đẩy!\n"
	.string "Không thấy đang xếp hàng hả?$"

SlateportCity_Text_AquaHasPolicy:
	.string "ĐỘI AQUA có chính sách là\n"
    .string "tập trung và giải tán tại\l"
    .string "các điểm hoạt động.$"

SlateportCity_Text_BossIsBrilliant:
	.string "ÔNG TRÙM của tụi tui rất là vĩ đại.\p"
	.string "Không biết ổng sẽ làm gì với\n"
	.string "BẢO TÀNG nữa?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Không biết kế hoạch mới là gì nữa?\p"
	.string "ÔNG TRÙM nhìn rất dữ nếu mà ổng giận,\n"
	.string "nên tốt nhất là đừng có làm hư việc…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "Nếu cần cái gì ở BẢO TÀNG,\n"
	.string "thì lấy hết luôn cho rồi!$"

SlateportCity_Text_DontButtIn:
	.string "Ê, ê!\n"
	.string "Đừng có xía vô!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Hàng dài hả?\p"
	.string "Làm tui nhớ hồi mà tui xếp hàng\n"
	.string "mua game đang hot…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Sao phải xếp hàng rồi trả tiền?\n"
	.string "Sao không chen vô luôn cho rồi!$"

SlateportCity_Text_WhatDoYouWant:
	.string "Hả?\n"
	.string "Muốn gì?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Không biết đọc hả?\n"
	.string "Để đọc cho!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Để coi…\p"
	.string "Um… hình như là nó nói là\n"
	.string "“Biển là vô tận.”\p"
	.string "Mm, hình như là nó\n"
	.string "nói vậy á.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Cằn nhằn…\p"
	.string "Phải nãy đem máy Game Boy Advance\n"
	.string "để chơi trong lúc chờ hàng là được rồi…\p"
	.string "Cằn nhằn…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Khi chiến dịch kết thúc, ta sẽ\n"
	.string "dắt các ngươi đi suối nước nóng!\p"
	.string "Thủ lĩnh tụi tui nói vậy đó.\n"
	.string "Nôn quá!$"

SlateportCity_Text_SeaIsSoWet:
	.string "Biển rộng quá…\p"
	.string "Có chăng là biển được tạo ra\n"
	.string "từ nước mắt của POKéMON?$"

SlateportCity_Text_SinkOldBoats:
	.string "Bạn có biết người ta làm gì với\n"
	.string "mấy con tàu cũ không?\p"
	.string "Người ta nhấn chìm xuống đáy biển,\n"
	.string "tạo thành nơi sống cho POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Mỗi lần tới đây là cô\n"
	.string "mua nhiều đồ đem về lắm.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Nếu bạn muốn đổi tên cho POKéMON,\n"
	.string "bạn nên lại chỗ ÔNG ĐẶT TÊN để ổng\l"
	.string "đặt tên giùm cho.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "POKéMON bạn nhận được khi trao đổi,\n"
	.string "thì không có đổi tên lại được.\p"
	.string "Bởi vì đó là cái tên mà chủ cũ đã\n"
	.string "dành hết tình thương vô.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Gần đây, HỘI THI ĐẤU đã được\n"
	.string "xây dựng ở TP.CẢNG.\p"
	.string "NHÀ THI ĐẤU cũng vui, nhưng mà\n"
	.string "HỘI THI ĐẤU cũng thú vị đó.\p"
	.string "Bạn cũng nên kiếm POKéMON nào\n"
	.string "mạnh cho HỘI THI ĐẤU đi!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "Tui tưởng đó là người nổi tiếng,\n"
	.string "tui tính lại xin một tấm hình.\p"
	.string "Nhưng mà ai đang được phỏng vấn vậy?\n"
	.string "THUYỀN TRƯỞNG SANG phải không?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Cái bà phóng viên đó\n"
	.string "nhìn rất đẹp và lịch sự.\p"
	.string "Sau này lớn lên, tui muốn\n"
	.string "làm nhà báo quốc tế!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "THUYỀN TRƯỞNG SANG nói là họ đã\n"
	.string "tìm thấy thứ gì đó ở dưới biển.\p"
	.string "Cái gì vậy ta?\n"
	.string "Không lẽ là?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Chuyện gì đây?\p"
	.string "THUYỀN TRƯỞNG trở lại đây với\n"
	.string "con cá lớn dưới biển sâu à?$"

SlateportCity_Text_AmIOnTV:
	.string "Ê! Bạn có thấy tui không?\n"
	.string "Tui có được lên tivi không?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Phỏng vấn lên tivi! Đây!\n"
	.string "THUYỀN TRƯỞNG là người nổi tiếng!$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY: Rồi, THUYỀN TRƯỞNG SANG,\n"
	.string "nhìn vô máy nè!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GIANG: À, à hiểu. Anh đã có\n"
	.string "những trải nghiệm quý giá…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "THUYỀN TRƯỞNG SANG: Dạ, đúng rồi.\n"
	.string "Tụi tui đang tính đi khám phá tiếp.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GIANG: Hay quá, thưa THUYỀN TRƯỞNG!\n"
	.string "Cảm ơn anh đã sắp xếp công việc\l"
	.string "để trò chuyện với chúng tôi.\p"
	.string "Chúng tôi mong được phỏng vấn anh\n"
	.string "với nhiều tin tức khám phá hơn nữa!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "THUYỀN TRƯỞNG SANG: Phù…\p"
	.string "Lần đầu được quay lên tivi.\n"
	.string "Run quá trời.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Ủa, {PLAYER}{KUN}!\n"
	.string "Vẫn khoẻ ha!\p"
	.string "Tụi tui có phát hiện lớn trong\n"
	.string "chuyến thám hiểm vừa rồi.\p"
	.string "Tụi tui tìm thấy hang động dưới nước ở\n"
	.string "ĐƯỜNG 128.\p"
	.string "Chắc đây là nơi sinh sống của\n"
	.string "POKéMON được cho là đã bị tuyệt chủng.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu…\n"
	.string "THUYỀN TRƯỞNG SANG thì phải.\p"
	.string "ĐỘI AQUA sẽ tiếp quản\n"
	.string "tàu ngầm của ngài!\p"
	.string "Sự phản đối của ngài là vô nghĩa!\n"
	.string "Hãy hợp tác với tôi!\p"
	.string "Fufufu…\n"
	.string "Nhìn mà học hỏi cách mà\l"
	.string "ĐỘI AQUA lên kế hoạch!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "THUYỀN TRƯỞNG SANG: Là sao vậy?\p"
	.string "Nghe như ai đó đang xài\n"
	.string "loa để phát ra vậy…\p"
	.string "Nhưng mà cái tiếng phát ra từ đâu?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Từ BẾN CẢNG đó!\p"
	.string "Cái tàu ngầm!\n"
	.string "Tụi nó đang tính cướp!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN}!\n"
	.string "Đi với tui!$"

SlateportCity_Text_BattleTentSign:
	.string "HỘI THI ĐẤU TP.CẢNG\n"
	.string "“Tới đây đi! Hỡi POKéMON mạnh nhất!”$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "XƯỞNG ĐÓNG TÀU của SANG\p"
	.string "“Tuyển: Thuỷ thủ có khả năng\n"
	.string "lái tàu trong mọi tình huống.”$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "XƯỞNG ĐÓNG TÀU của SANG\p"
	.string "“Bến phà S.S. TIDAL gần hoàn thiện\n"
	.string "để phục vụ luân chuyển hàng đường biển\l"
	.string "cho TP.CẢNG và TP.BIỂN.”$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "XƯỞNG ĐÓNG TÀU của SANG\p"
	.string "“Đi phà S.S. TIDAL từ TP.CẢNG\n"
	.string "qua TP.BIỂN được thực hiện tại\l"
	.string "BẾN CẢNG.”$"

SlateportCity_Text_PokemonFanClubSign:
	.string "CLB HÂM MỘ POKéMON\n"
	.string "“Kêu gọi Fan POKéMON tới đây!”$"

SlateportCity_Text_OceanicMuseumSign:
	.string "“Biển vô tận\n"
	.string "duy trì sự sống.”\p"
	.string "BẢO TÀNG BIỂN SÂU$"

SlateportCity_Text_CitySign:
	.string "TP.CẢNG\p"
	.string "“Nơi con người và POKéMON\n"
	.string "đi lại.”$"

SlateportCity_Text_MarketSign:
	.string "CHỢ CẢNG\n"
	.string "“Bán đồ có 1 không 2, không đụng hàng!”$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "BẾN CẢNG\p"
	.string "“Tàu S.S. TIDAL đang được đóng\n"
	.string "ở XƯỞNG ĐÓNG TÀU.\p"
	.string "“Dịch vụ dự kiến sẽ\n"
	.string "được mở sớm.”$"

SlateportCity_Text_HarborSign:
	.string "BẾN CẢNG\p"
	.string "“Tận hưởng chuyến du ngoạn\n"
	.string "trên tàu S.S. TIDAL.”$"

SlateportCity_Text_NameRatersHouseSign:
	.string "NHÀ của ÔNG ĐẶT TÊN\n"
	.string "“Nhận xét biệt danh POKéMON.”$"

SlateportCity_Text_ExplainBerries:
	.string "Con biết cái này chưa?\p"
	.string "Nếu POKéMON hoang bị thương, nó có thể\n"
	.string "nhai TRÁI CÂY để phục hồi.\p"
	.string "Con biết cái này chưa?\p"
	.string "Có người thấy vậy mới nghĩ cách\n"
	.string "làm ra thuốc từ TRÁI CÂY.\p"
	.string "Con biết cái này chưa?\p"
	.string "Để biến TRÁI CÂY thành thuốc,\n"
	.string "người ta phải nghiền nát thành bột.\p"
	.string "Hình như con cũng hứng thú\n"
	.string "với TRÁI CÂY!\p"
	.string "Cô có cái này cũng hay, muốn\n"
	.string "gởi tặng con.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "Dạo gần đây cô được TRUNG TÂM POKéMON\n"
	.string "làm cho cái máy nghiền TRÁI CÂY.\p"
	.string "Con biết cái này chưa?\p"
	.string "Có máy NGHIỀN TRÁI CÂY nằm ở\n"
	.string "trong GÓC trên lầu á.\p"
	.string "Con sử dụng máy đó làm giùm cô\n"
	.string "BỘT TRÁI CÂY được không?\p"
	.string "Cô sẽ làm thuốc cho con nếu con\n"
	.string "đem cho cô thiệt nhiều BỘT TRÁI CÂY.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Con đưa cô\n"
	.string "BỘT TRÁI CÂY hả?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Con muốn gì để\n"
	.string "đổi lại?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "Rồi, con muốn đổi BỘT TRÁI CÂY\n"
	.string "để lấy 1 {STR_VAR_1} đúng chưa?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Trời ơi. Con không có đem đủ\n"
	.string "BỘT TRÁI CÂY.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "BỘT TRÁI CÂY này tốt đó.\n"
	.string "Chắc sẽ làm ra được thuốc tốt.\p"
	.string "Con có muốn đổi thêm BỘT TRÁI CÂY\n"
	.string "để lấy cái khác nữa không?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "Rồi! Khi nào có thêm BỘT TRÁI CÂY,\n"
	.string "thì nhớ đem lại cho cô nha!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Quay lại đây nếu con muốn đổi\n"
	.string "BỘT TRÁI CÂY để lấy thuốc.\p"
	.string "Con biết cái này chưa?\p"
	.string "Ngày nào cô cũng bán ở đây hết.$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SƠN: Hmm?\n"
	.string "Hình như chú có gặp con ở đâu rồi.\p"
	.string "Chú có giới thiệu mình chưa ta?\n"
	.string "Nếu chưa thì, chú tên là SƠN.\p"
	.string "Chú mới vừa thấy ĐỘI AQUA chạy trốn\n"
	.string "khỏi đây mà cứ như bị ai hối vậy.\p"
	.string "Để coi--con đuổi tụi nó đi hả?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SƠN: Hmm…\n"
	.string "Có thể, có thể, người này…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SƠN: Được rồi! Chú nghĩ\n"
	.string "tụi mình có thể làm bạn.\p"
	.string "Nên là hãy lưu số nhau vô\n"
	.string "BẢN ĐỒ.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Lưu số cái người tên SƠN này\n"
	.string "vô BẢN ĐỒ.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SƠN: Chú cũng muốn đi theo con nữa,\n"
	.string "nhưng mà giờ chú phải đi kiếm\l"
	.string "thêm mấy tài năng trẻ rồi.\p"
	.string "Nên là chú sẽ đi lang thang\n"
	.string "qua mấy thị trấn khác nữa.\p"
	.string "Gặp lại sau nha, {PLAYER}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SƠN: Ủa, ê!\n"
	.string "{PLAYER} nè phải không?\p"
	.string "Để coi--con tính tham gia\n"
	.string "thử thách HỘI THI ĐẤU đúng không?\p"
	.string "Đúng rồi đó! Ý hay đó!\n"
	.string "Sáng kiến rất hay!\p"
	.string "Sau cùng, 1 NHL mạnh như con cực kỳ\n"
	.string "phù hợp cho HỘI THI ĐẤU mà!\p"
	.string "Cố lên!$"

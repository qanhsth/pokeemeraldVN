PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hửmm…\n"
	.string "Chắc không ai thấy đâu…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Chao xìn, bạn có thấy POKéMON\n"
	.string "tên là SHROOMISH ở đây không?\p"
	.string "Tui rất là thích POKéMON đó.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Tui tính phục kích bạn, mà bạn\n"
	.string "cứ đi lòng vòng trong\l"
	.string "RỪNG HOA CAM này hoài.\p"
	.string "Chờ hoài mệt quá, thôi tui tới đây!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Em! Mấy ông NGHIÊN CỨU VIÊN ở DEVON!\p"
	.string "Đưa mấy cái này giùm đi!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Trời đất ơi!\p"
	.string "Bạn là NHL POKéMON, phải không?\n"
	.string "Bạn phải giúp tui đó nha!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hả? Nhà ngươi tính làm gì?\n"
	.string "Tính bảo vệ nó hả?\p"
	.string "Không ai được phép vượt qua\n"
	.string "ĐỘI AQUA, kể cả là con nít!\p"
	.string "Lại đây đấu với ta coi!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Giỡn mặt hả? Sao mạnh vậy?$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Gừ… ĐỘI AQUA mà\n"
	.string "cũng dám đối đầu!\l"
	.string "Mai mốt gặp ta, đấu lại nha!\p"
	.string "Ta cũng muốn nói vậy lắm,\n"
	.string "mà hết POKéMON rồi…\p"
	.string "Ủa, ê, ĐỘI AQUA đang theo\n"
	.string "dấu cái gì đó ở TP.KIM THÁN.\p"
	.string "Thôi cho ngươi đi đó!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Hú vía…\n"
	.string "Hết hồn!\p"
	.string "Nhờ bạn mà, hắn không cướp\n"
	.string "đi mấy tờ giấy quan trọng này.\p"
	.string "Tui biết mà, cho bạn cái\n"
	.string "CẦU LỚN để cảm ơn nè!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Cái ông ĐỘI AQUA đó nói là\n"
	.string "tụi nó đang theo dấu cái gì\l"
	.string "ở TP.KIM THÁN phải không?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Uh-oh! Nguy rồi!\n"
	.string "Không lãng phí thời gian được nữa!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Bạn bỏ nhiều đồ quá.\n"
	.string "Sao tui cho bạn cái CẦU LỚN này được?$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Tui bắt 1 đống POKéMON luôn nè!\p"
	.string "Đi, đi, đi thôi!\n"
	.string "Tổ đội POKéMON CÔN TRÙNG của tui ơi!$"

PetalburgWoods_Text_ICouldntWin:
	.string "Tui có quá trời POKéMON,\n"
	.string "mà không thắng nổi…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Tui bắt nhiều POKéMON quá.\n"
	.string "Giờ hết CẦU POKéMON luôn rồi.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Nếu bạn đem POKéMON hệ BỌ đi học,\n"
	.string "chắc chắn bạn sẽ nổi tiếng nhất trường!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Nếu mà thua thì sao nổi tiếng được.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Nếu bạn có POKéMON hệ BỌ lớn,\n"
	.string "người ta sẽ rất nể bạn.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Tui muốn đấu lại khi mà\n"
	.string "POKéMON hệ BỌ của tui lớn lên!\p"
	.string "Cho tui lưu số bạn vô BẢN ĐỒ nha!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Tui muốn đấu lại khi mà\n"
	.string "POKéMON hệ BỌ của tui lớn lên!\p"
	.string "Cho tui lưu số bạn vô BẢN ĐỒ nha!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "POKéMON hệ BỌ của tui lớn rồi.\n"
	.string "Tui sẽ nổi tiếng lại thôi.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Nếu mà thua chắc không ai biết tui luôn.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Nếu có POKéMON mạnh thì sẽ\n"
	.string "được nổi tiếng phải không?\l"
	.string "Vậy thì tui sẽ luyện tập hết mình.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Ô, chào đằng kia!\n"
	.string "POKéMON của bạn sao rồi?\p"
	.string "Nếu mà POKéMON còn yếu với không\n"
	.string "muốn tranh đấu, thì bạn nên tránh\l"
	.string "xa mấy bụi cỏ cao cao này ra đi.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Đôi khi, có những thứ nằm ở dưới\n"
	.string "đất, đi ngang qua mà không để ý.\p"
	.string "Bởi vậy nên là lúc nào đi bộ\n"
	.string "tui cũng coi cho kỹ hết á.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Trời ghê dạ!\n"
	.string "HUY HIỆU NHÀ THI ĐẤU KIM THÁN nè!\p"
	.string "Chắc bạn là NHL phải không?\n"
	.string "Bạn xài thử cái này đi.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "HẠT KỲ DIỆU đó.\n"
	.string "Nếu POKéMON cầm cái này vô,\l"
	.string "tuyệt chiêu hệ CỎ sẽ mạnh hơn.\p"
	.string "Ngoài ra, tui nghĩ là còn\n"
	.string "rất nhiều vật phẩm hữu ích khác\l"
	.string "mà POKéMON có thể cầm được.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "MẸO cho NHL\p"
	.string "Bất kỳ POKéMON nào xuất hiện trên\n"
	.string "sân đều được thưởng KINH NGHIỆM.\p"
	.string "Nếu muốn luyện cấp cho POKéMON yếu,\n"
	.string "hãy xếp nó lên đầu tổ đội.\p"
	.string "Khi mà trận đấu bắt đầu, hãy đổi\n"
	.string "con khác lên. Nó vẫn được hít\l"
	.string "KINH NGHIỆM mà không bị gì hết.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "MẸO cho NHL\p"
	.string "Ngoài MÁU (HP) ra, POKéMON còn có\n"
	.string "SỐ LẦN XÀI CHIÊU (PP), nó sẽ tiêu\l"
	.string "hao mỗi khi xài chiêu thức trong trận.\p"
	.string "Nếu POKéMON hết PP, thì hãy đem nó\n"
	.string "tới TRUNG TÂM POKéMON để hồi lại.$"


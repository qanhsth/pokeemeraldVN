Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Tui là người MÊ HOÁ THẠCH…\n"
	.string "Tui là một người yêu thích HOÁ THẠCH…\p"
	.string "Bạn có muốn HOÁ THẠCH không?\p"
	.string "Nhưng mà HOÁ THẠCH ở chỗ này là\n"
	.string "của tui rồi… Không cho bạn được…\p"
	.string "Nếu mà bạn rất muốn có HOÁ THẠCH,\n"
	.string "thì hãy đi lại sa mạc chỗ mà\l"
	.string "có tảng đá lớn với cát á, chỗ đó\l"
	.string "sẽ có HOÁ THẠCH…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Bạn tìm thấy HOÁ THẠCH rồi hả?\n"
	.string "Đẹp quá… Đẹp như mơ vậy…\p"
	.string "Bạn tính làm gì với\n"
	.string "HOÁ THẠCH đó?\p"
	.string "Tui nghe nói là, DEVON đang thực hiện\n"
	.string "nghiên cứu để phục sinh POKéMON từ\l"
	.string "HOÁ THẠCH…\p"
	.string "Tui yêu HOÁ THẠCH của mình, nên là\n"
	.string "tui sẽ không bao giờ làm chuyện đó…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "HOÁ THẠCH đúng là… hoàn mỹ…\n"
	.string "Đẹp như mơ vậy…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Ụa…\n"
	.string "Đường đó đi không được đâu…\p"
	.string "Nãy tui đang đào cái tự nhiên…\n"
	.string "Cái tường nó sụp xuống…\p"
	.string "Không chừng giờ ở dưới đó\n"
	.string "thành cái hang luôn rồi…\p"
	.string "Nhưng mà tui không có đụng tới tại\n"
	.string "tui nghĩ chắc không có HOÁ THẠCH đâu…$"


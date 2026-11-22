Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Cái ĐƯỜNG HẦM KIM CHI đó…\p"
	.string "Hồi đầu, tụi tui có một đội thi công\n"
	.string "để khoan đá bằng máy móc hiện đại lắm.\l"
	.string "Mà phải tạm ngưng.\p"
	.string "Tại vì là tụi tui làm ảnh\n"
	.string "hưởng xấu tới POKéMON trong\l"
	.string "khu vực này.\p"
	.string "Nên là giờ tụi tui cứ la\n"
	.string "cà ở đây, không biết làm gì.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Có một người đang đào hầm\n"
	.string "tới GIẢN ĐƠN, mà có mình ổng thôi.\l"
	.string "Ổng rất muốn được đi qua hầm.\p"
	.string "Ổng còn nói là nếu mà đào từ từ\n"
	.string "không xài máy, thì ổng sẽ không\l"
	.string "làm phiền POKéMON, với cũng tránh\l"
	.string "làm hại môi trường tự nhiên.\p"
	.string "Không biết ổng làm xong chưa nữa.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Muốn đi qua GIẢN ĐƠN mà không đi\n"
	.string "qua cái HẦM này, thì bạn phải vượt\l"
	.string "biển tới THÔN ĐẢO, chèo qua TP.CẢNG,\l"
	.string "rồi đi lên TP.HOA TÍM.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Biết gì chưa? ĐƯỜNG HẦM qua\n"
	.string "GIẢN ĐƠN được thông rồi đó!\p"
	.string "Đôi khi chỉ cần hy vọng đủ\n"
	.string "nhiều thì giấc mơ sẽ thành hiện thực.$"


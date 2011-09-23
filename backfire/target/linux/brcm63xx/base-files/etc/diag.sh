#!/bin/sh
# Copyright (C) 2007 OpenWrt.org

status_led="power"

led_set_attr() {
	[ -f "/sys/class/leds/$1/$2" ] && echo "$3" > "/sys/class/leds/$1/$2"
}

status_led_set_timer() {
	led_set_attr $status_led "trigger" "timer"
	led_set_attr $status_led "delay_on" "$1"
	led_set_attr $status_led "delay_off" "$2"
}

status_led_on() {
	led_set_attr $status_led "trigger" "none"
	led_set_attr $status_led "brightness" 255
}

status_led_off() {
	led_set_attr $status_led "trigger" "none"
	led_set_attr $status_led "brightness" 0
}

set_state() {
	case "$1" in
		preinit)
		status_led_set_timer 10 10
		;;
		failsafe)
		status_led_set_timer 50 50
		;;
		network)
		led_set_attr dsl "brightness" 255		
		;;		
		wireless)
		led_set_attr wps "brightness" 255		
		;;
		firewall)
		led_set_attr usb "brightness" 255		
		;;
		done)
		status_led_on
		led_set_attr wps "brightness" 0
		led_set_attr usb "brightness" 0
		;;
	esac
}
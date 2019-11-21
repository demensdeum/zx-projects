 
    org 32768
    ; load screen address
    ld de,16384
    ld a,255
    ; will repeat 8 times
    ld b,8
    draw_loop:
      ld (de), a
      inc d ; go to next y line
      djnz draw_loop  ; loop if b is not zero
    main:  
      jr main      ;loop forever!   
    end 32768

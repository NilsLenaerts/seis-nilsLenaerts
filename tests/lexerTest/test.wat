local.get 0
local.get 1
i32.add ;;test comment
i32.const 10
i32.const 20
i32.add (;testing a whole block ;
i32.add;)
i32.const 30
i32.add
i32.const 60
i32.eq

i32.const "\"hello\" said the man"
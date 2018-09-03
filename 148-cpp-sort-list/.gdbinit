set args < test/173112966.in
define plist
  set var $n = $arg0
  set var $end = $arg1
  while $n != $end
    printf "%d ", $n->val
    set var $n = $n->next
  end
  printf "\n"
end
b 43
r
disp mid->val
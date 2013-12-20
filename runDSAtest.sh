echo "-------------Running tests on Binary Search--------------------"
sh runTest.sh ./binarySearch/binarySearch.c | grep -A1 "fail"
echo

echo "-------------Running tests on Linear Queue--------------------"
sh runTest.sh ./linearQueue/queue.c | grep -A1 "fail"
echo

echo "-------------Running tests on circuler Queue--------------------"
sh runTest.sh ./circularQueue/circularQueue.c | grep -A1 "fail"
echo

echo "-------------Running tests on Stack--------------------"
sh runTest.sh ./stack/stack.c | grep -A1 "fail"
echo

echo "-------------Running tests on Stack without Using MEM function--------------------"
sh runTest.sh ./stackWithoutMem/stackWithoutMem.c | grep -A1 "fail"
echo

echo "-------------Running tests on Stack Using Linked List--------------------"
sh runTest.sh ./stackUsingLinkedList/stackUsingLinkedList.c -need:./linkedList/linkedList.c | grep -A1 "fail"
echo

echo "-------------Running tests on parentheses Matcher--------------------"
sh runTest.sh ./parenthesesMatcher/parenthesesMatcher.c -need:./parenthesesMatcher/stack.c| grep -A1 "fail"
echo

echo "-------------Running tests on Linked List--------------------"
sh runTest.sh ./linkedList/linkedList.c | grep -A1 "fail"
echo


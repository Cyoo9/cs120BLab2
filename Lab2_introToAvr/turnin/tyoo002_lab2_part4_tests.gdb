# Test file for "Project name: Lab2_introToAV Partners name [none]:"

test "PINA 0xF0 PINB 0x0F PINC 0x00 => PORTD: 0xFF"
setPINA 0xF0
setPINB 0x0F
setPINC 0x00
continue 5
expectPORTD 0xFF
checkResult

test "PINA 0x30 PINB 0x20 PINC 0x10 => PORTD: 0x60"
setPINA 0x30
setPINB 0x20
setPINC 0x10
continue 5
expectPORTD 0x60
checkResult

TEST "PINA 0x01 PINB 0X02 PINC 0X03 => PORTD: 0X06"
setPINA 0x01
setPINB 0x02
setPINC 0x03
continue 5
expectPORTD 0x04
checkResult
 
# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n


# Add tests below

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n

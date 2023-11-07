# echo-lib
Echo request and reply message lib

## Infrastructure options

_Coming soon (ICMP)_

## Usage example

```c
    Listener listener = NewMockListener();

    StartMockListening(listener); // Sync

    DestroyListener(&listener);
```

## Tests

### Run unit tests

``` bash
python3 run_tests.py
```

### Run static checks

``` bash
python3 run_static_check.py
```

## Contribute

_Any idea or improvement is welcome. Feel free to branch and Pull Request for contributions, just, please, don't commit directly to develop or main histories. You can also get in contact with 'lohan.chuan123@gmail.com' or fork the repository._

### Porting

The following must be implemented to add `echo` a new protocol type

- `<PROTOCOL>Flush` (function)
- `<PROTOCOL>StartReceiving` (function)
- `New<PROTOCOL>Listener` (macro)
- `Start<PROTOCOL>Listening` (macro)

Example:

``` c
#define NewMockListener() NewListener(&MockStartReceiving, &MockFlush)
#define StartMockListening(listener) StartListening(listener, "HELLO WORLD\0")

/********************************************************************
 * This function flushes a message to an output
 * 
 * Inputs:
 *  - Message
 ********************************************************************/
void MockFlush(Message message);

/********************************************************************
 * This function receives a message and forwards to Listener
 * 
 * Inputs:
 *  - Listener
 ********************************************************************/
Bool MockStartReceiving(Listener listener);
```

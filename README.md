# Jenkins_Moser_CSCI_Final_Project

Objective -
    The goal of Dean Moser and Joshua Jenkin's CSCI2270 final project
    is to apply what we have been learning into a functional program.
    We plan to utilize our recently developed understanding of hash-tables
    to read in an entire list of words from the dictionary from a file,
    assign hash values to them and use that table as a gradient for word
    encryption of a user-input phrase. The phrase then cannot be decrypted
    without the correct integer of gradient shift. There are a few foreseeable
    problems with this idea, however in the event of hash collisions.

Possible Roadblocks -
    Read in words may have the same hash value.
    When shifting word by gradient, if the destination has no words in the hash.

    When attempting to resolve these problems, we should try to find a solution
    which does not compromise the integrity of the encryption's security.
    ie we shouldn't display which words were in fact shifted or not in a way
    that the user can list down the non-changed words and play the equivalent
    of hangman to solve the original phrase.

Ideas for Issue Prevention -
    Instead of only revealing the encrypted message, extend the message to
    include encryption notes that are also encrypted.
    ie  "<e0-j> <n0-j>" or "<e0> <n0> <e1> <n1>" etc.
     - (^ possibility of additionally including many different integrations of the
    notes in with the encrypted message to confuse any attempting to break
    the code with additional keys of that sub-encryption in some super-secret
    location of the entire message, based on the size of the input message;
    but will likely leave it alone for the sake of our deadline)

    For collisions, we will use the same integration of key concept to
    determine what index of the hash's vector the original message's word
    was to ensure accurate output of decryption

Note -
    The message will only encrypt real words.
     - (^ could, with added complication, eventually resolve this with a more
    traditional ascii enc. and some key word within the encrypted encryption
    notes tell the system of the location of said "type2" encryption within
    the encrypted message, but we will leave that alone for now)

Understanding - THE PLANO STANO
    Pre-Program:
        read in file of dictionary listing
        save in a hash table
            [0]     [real]
            [1]     [this]
            [2]     [a]
            [3]     [of] [words] [string]
            [4]     [is]
            [5]     [test]
            [6]     [dub]
            [7]     [step]
            [8]     [be]
            [9]     []
            [10]    [absolutely] [nasty]
    Input:
|           "this is a test string of real words"
        turns into an array
            [this] [is] [a] [test] [string] [of] [real] [words] <msg (size) 8>
    Computation:
        creates an additional array of same size as original message for
        key notes
            [] [] [] [] [] [] [] [] <notes 8>
        creates a doubly sized array + one space as room for a key
        word having to do with location of notes vs location of message.
            [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] <out 17>
        finds a random number within the hash size and associates a
        key-location word with said hash (re-rolls for empty hash)
            [be] <w/ hash val 8>
        places said key-location word in some undisclosed (constant for
        simplicity) location in the out array
            [] [] [] [] [] [] [] [] [be] [] [] [] [] [] [] [] [] <o17>
        performs the shift of input and logs the changes based on user
        input integer "7"
            [    ] [    ] [!] [    ] [2         ] [0    ] [    ] [1    ] <tmp 8>
            [this] [is  ] [a] [test] [string    ] [of   ] [real] [words] <m8>
            ->
            [be  ] [real] [a] [this] [absolutely] [nasty] [step] [nasty] <m8>
        converts log to words via another preset code (based on key-location
        value which is also re-rolled if any index notifiers end up in an
        empty hash) !!BIG ERROR MAY OCCUR if no available path without empty
        hashes!!
            [] [] [!   ] [] [2 ] [0  ] [] [1   ] <tmp 8>
            ->
            [] [] [test] [] [be] [dub] [] [step] <n8>
        fills remainder of notes with non-key words
            [  ] [     ] [test] [  ] [be] [dub] [ ] [step] <n8>
            ->
            [of] [nasty] [test] [is] [be] [dub] [a] [step] <n8>
        based on function of key-location value "be"
        (hash 8) (this case odd/even) place notes and message in orientation
            [be] [real] [a] [this] [absolutely] [nasty] [step] [nasty] <m8>
            +
            [of] [nasty] [test] [is] [be] [dub] [a] [step] <n8>
            ->
    Output:
|           [be] [of] [real] [nasty] [a] [test] [this] [is] [be] [absolutely] [be] [nasty] [dub] [step] [a] [nasty] [step] <o17>
        !so nonsensical, it almost makes sense!
    Decryption:
        Input:
                [be] [of] [real] [nasty] [a] [test] [this] [is] [be] [absolutely] [be] [nasty] [dub] [step] [a] [nasty] [step] <i17>
            finds the key-location word "be"
                                                                [^ ]
            based on "be" (hash 8) locates notes and msg
                8 means even means alternating
                msg
                ->
                [be] [real] [a] [this] [absolutely] [nasty] [step] [nasty] <m8>
                +
                [of] [nasty] [test] [is] [be] [dub] [a] [step] <n8>
            eradicates useless notes info
                [be] [real] [a] [this] [absolutely] [nasty] [step] [nasty] <m8>
                [  ] [    ] [!] [    ] [2         ] [0    ] [    ] [1    ] <tmp 8>
            waits for decrypt code 7 then shifts -7
                [be] [real] [a] [this] [absolutely] [nasty] [step] [nasty] <m8>
                -
                7
                +
                [] [] [!] [] [2] [0] [] [1] <tmp 8>
                ->
|               [this] [is] [a] [test] [string] [of] [real] [words] <o8>

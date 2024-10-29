class Relay
{
public:
    Relay(char *Name, int RelayNo, bool state);

private:
    char *Name_;
    int RelayNo_;
    bool state_; /// Status (0=aus, 1=an)
};

Relay::Relay(char *Name, int RelayNo, bool state) : Name_(Name),
                                                    RelayNo_(RelayNo),
                                                    state_(state)
{
}


from dataclasses import dataclass

@dataclass
class UseInfo:
    next_use: int = 0
    active: bool = False

    def __post_init__(self):
        self.next_use = int(self.next_use)
        self.active = bool(self.active)

    def __str__(self):
        return f"({self.next_use},{ 'Y' if self.active else '^'})"

    def no_use(self):
        return self.next_use == 0 and not self.active

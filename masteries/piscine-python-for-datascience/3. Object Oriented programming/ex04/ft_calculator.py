class calculator:

    @staticmethod
    def dotproduct(V1: list[float], V2: list[float]) -> None:
        """Calculates the dot product of 2 vectors"""

        print(f"Dot product is: {sum(V1[x]*V2[x] for x in range(len(V1)))}")

    @staticmethod
    def add_vec(V1: list[float], V2: list[float]) -> None:
        """Calculates the addition of 2 vectors"""

        print(f"Add Vector is: {[float(V1[x]+V2[x]) for x in range(len(V1))]}")

    @staticmethod
    def sous_vec(V1: list[float], V2: list[float]) -> None:
        """Calculates the subtraction of 2 vectors"""

        print("Sous Vector is: ", end='')
        print(f"{[float(V1[x]-V2[x]) for x in range(len(V1))]}")

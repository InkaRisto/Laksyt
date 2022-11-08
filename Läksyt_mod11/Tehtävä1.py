class Publication:
    def __init__(self, name):
        self.name = name

    def print_info(self):
        print(f'Julkaisun nimi: {self.name}')


class Book(Publication):
    def __init__(self, name, author, pages):
        super().__init__(name)
        self.pageCount = pages
        self.author = author

    def print_info(self):
        super().print_info()
        print(f'Kirjailija: {self.author}\nSivumäärä: {self.pageCount}\n')


class Magazine(Publication):
    def __init__(self, name, editor):
        super().__init__(name)
        self.editor = editor

    def print_info(self):
        super().print_info()
        print(f'Päätoimittaja: {self.editor}\n')


pub1 = Magazine('Aku Ankka', 'Aki Hyyppä')
pub2 = Book('Hytti n.o 6', 'Rosa Liksom', 200)

pub1.print_info()
pub2.print_info()
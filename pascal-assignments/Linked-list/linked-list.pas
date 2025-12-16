program LinkedListDemo;

type
  NodePtr = ^Node;

  Node = record
    data : integer;
    next : NodePtr;
  end;

var
  head : NodePtr;
  size : integer;

{ insert at index }
procedure InsertAt(index, value : integer);
var
  newNode, current : NodePtr;
  i : integer;
begin
  if (index < 0) or (index > size) then
  begin
    writeln('Error: Invalid index');
    exit;
  end;

  new(newNode);
  newNode^.data := value;
  newNode^.next := nil;

  if index = 0 then
  begin
    newNode^.next := head;
    head := newNode;
  end
  else
  begin
    current := head;
    for i := 0 to index - 2 do
      current := current^.next;

    newNode^.next := current^.next;
    current^.next := newNode;
  end;

  size := size + 1;
end;

{ delete at index }
procedure DeleteAt(index : integer);
var
  current, temp : NodePtr;
  i : integer;
begin
  if size = 0 then
  begin
    writeln('Error: List is empty');
    exit;
  end;

  if (index < 0) or (index >= size) then
  begin
    writeln('Error: Invalid index');
    exit;
  end;

  if index = 0 then
  begin
    temp := head;
    head := head^.next;
  end
  else
  begin
    current := head;
    for i := 0 to index - 2 do
      current := current^.next;

    temp := current^.next;
    current^.next := temp^.next;
  end;

  dispose(temp);
  size := size - 1;
end;

{ print list }
procedure Traverse;
var
  current : NodePtr;
begin
  if head = nil then
  begin
    writeln('[empty]');
    exit;
  end;

  current := head;
  while current <> nil do
  begin
    write(current^.data, ' ');
    current := current^.next;
  end;
  writeln;
end;

begin
  { start }
  head := nil;
  size := 0;

  InsertAt(0, 10);
  InsertAt(1, 20);
  InsertAt(1, 15);
  InsertAt(3, 25);

  write('List after insertions: ');
  Traverse;

  DeleteAt(1);
  write('List after deleting index 1: ');
  Traverse;

  DeleteAt(0);
  write('List after deleting index 0: ');
  Traverse;
end.

program ArrayListDemo;

const
  MAX_SIZE = 100;

var
  data : array[0..MAX_SIZE-1] of integer;
  size : integer;
  i    : integer;

{ insert value at index }
procedure InsertAt(index, value : integer);
var
  i : integer;
begin
  if size = MAX_SIZE then
  begin
    writeln('List is full');
    exit;
  end;

  if (index < 0) or (index > size) then
  begin
    writeln('Invalid index');
    exit;
  end;

  { shift elements to the right }
  for i := size downto index + 1 do
    data[i] := data[i-1];

  data[index] := value;
  size := size + 1;
end;

{ delete value at index }
procedure DeleteAt(index : integer);
var
  i : integer;
begin
  if size = 0 then
  begin
    writeln('List is empty');
    exit;
  end;

  if (index < 0) or (index >= size) then
  begin
    writeln('Invalid index');
    exit;
  end;

  { shift elements to the left }
  for i := index to size - 2 do
    data[i] := data[i+1];

  size := size - 1;
end;

{ print list }
procedure Traverse;
var
  i : integer;
begin
  if size = 0 then
  begin
    writeln('List is empty');
    exit;
  end;

  for i := 0 to size - 1 do
    writeln('The data at ', i, ' is ', data[i]);
end;

begin
  { start }
  size := 0;

  InsertAt(0, 12);
  InsertAt(0, 20);
  InsertAt(0, 90);
  InsertAt(0, 120);
  InsertAt(4, 1000);

  Traverse;
  writeln('Size after insertions: ', size);

  DeleteAt(0);
  DeleteAt(3);

  writeln('Array after deletion');
  Traverse;
  writeln('Size after two deletions: ', size);
end.

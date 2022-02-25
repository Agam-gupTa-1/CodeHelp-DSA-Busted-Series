void removeDuplicates(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    map<int, bool> visited;
    Node *temp = head;
    while (temp->next)
    {
        visited[temp->data] = true;
        if (visited[temp->next->data] == true)
        {
            Node *t = temp->next;
            temp->next = t->next;
            delete t;
            t = NULL;
        }
        else
        {
            temp = temp->next;
        }
    }
    return;
}
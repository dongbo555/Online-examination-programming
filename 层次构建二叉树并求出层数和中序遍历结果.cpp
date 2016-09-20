void dfs(TreeNode * head){
	if (head != NULL){
		dfs(head->left);
		cout << head->val << " ";
		dfs(head->right);
	}

}

int main(){
	int n;
	cin >> n;
	while (n--){
		int a;
		cin >> a;
		vector<int> num;
		while (a != -1){
			num.push_back(a);
			cin >> a;
		}
		queue<TreeNode *> queues;
		TreeNode * head=NULL;
		int level = 0;
		for (int i = 0; i < num.size(); i++){
			TreeNode * node = new TreeNode(num[i]);
			if (i == 0){	
				if (num[i] != 0){
					head = node;
					queues.push(node);
					queues.push(NULL);
				}
			}
			else{
				TreeNode * p = queues.front();
				if (i % 2 == 1){
					if (num[i] != 0){
						queues.push(node);
						p->left = node;
					}
						
				}
				else{
					if (num[i] != 0){
						p->right = node;
						queues.push(node);
					}
					queues.pop();
					if (queues.front() == NULL){
						level++;
						queues.push(NULL);
						queues.pop();
					}
				}
			}
		}
		while (!queues.empty()){
			if (queues.front() == NULL){
				level++;
				queues.pop();
				break;
			}
			queues.pop(); 
		}
		if (!queues.empty()){
			level++;
		}
		cout << level << " ";
		dfs(head);
		cout << endl;
	}
	return 0;
}

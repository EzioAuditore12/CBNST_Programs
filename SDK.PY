import boto3

# Create a SageMaker client
client = boto3.client('sagemaker')

# Stop the notebook instance
response = client.stop_notebook_instance(
    NotebookInstanceName='spam-ham-model'
)

print(response)
